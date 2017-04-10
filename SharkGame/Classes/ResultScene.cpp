#include "TitleScene.h"
#include "ResultScene.h"
#include "audio/include/AudioEngine.h"

USING_NS_CC;


using namespace experimental;

ResultScene* ResultScene::create()
{
	ResultScene *pRet = new(std::nothrow) ResultScene();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

// 初期化
bool ResultScene::init()
{
	// 基底クラスの初期化
	if (!Scene::init())
	{
		// 基底クラスの初期化が失敗なら、異常終了
		return false;
	}

	//音の取得
	int resultbgm = AudioEngine::play2d("resultbgm.mp3");

	AudioEngine::setLoop(resultbgm, true);


	//画面の縦横のサイズを取得する
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	//背景の画像を取得
	Sprite* background = Sprite::create("gameover.png");

	//背景の画像を画面中央に表示
	background->setPosition(Point(winSize.width / 2, winSize.height / 2));
	//background->setPosition((Vec2(480, 320)));

	//画像のサイズの調整
	background->setScale(1.4f);

	addChild(background,0);

	//スタートボタン画像
	ui::Button* resulttitle = ui::Button::create("Restart-button.png");
	resulttitle->setPosition(Point(480, 200));
	resulttitle->setScale(1.0f);
	this->addChild(resulttitle);

	// 毎フレーム更新を有効化
	scheduleUpdate();

	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ResultScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	resulttitle->addTouchEventListener(CC_CALLBACK_2(ResultScene::onButtonClick, this));

	// 初期化が正常終了
	return true;
}

// タッチ開始時コールバック
bool ResultScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	return false;
}


//自動でシーンを変更の場合（消えるバグ2回に１回の割合あり）
void ResultScene::update(float delta)
{
	////リザルトシーンからタイトルシーンへ//
	//Scene* nextScene = TitleScene::create();

	////リザルトシーンから2秒たったらブラックアウトしてタイトルシーンへ戻る
	//TransitionFade* fade = TransitionFade::create(10.0f, ResultScene, Color3B::BLACK);
	
	//// 次のシーンに移行
	//_director->replaceScene(nextScene);
	
	////今のシーンを削除
	//Director::getInstance()->replaceScene(fade);

}

////ボタンを押してシーン変更
void ResultScene::onButtonClick(Ref* ref, cocos2d::ui::Widget::TouchEventType eventType)
{
	if (eventType == ui::Widget::TouchEventType::ENDED)
	{
		AudioEngine::uncache("resultbgm.mp3");

		// 次のシーンを作成する
		Scene* nextScene = TitleScene::create();

		// 次のシーンに移行
		_director->replaceScene(nextScene);
	}
}
