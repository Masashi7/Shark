#include "AppDelegate.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "audio\include\AudioEngine.h"

using namespace cocos2d::experimental;

USING_NS_CC;

TitleScene* TitleScene::create()
{
	TitleScene *pRet = new(std::nothrow) TitleScene();
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
bool TitleScene::init()
{
	// 基底クラスの初期化
	if (!Scene::init())
	{
		// 基底クラスの初期化が失敗なら、異常終了
		return false;
	}

	//BGM再生
	titlebgm = AudioEngine::play2d("titlebgm.mp3");
	
	//ループ再生
	AudioEngine::setLoop(titlebgm, true);

	// 背景画像
	Sprite* background = Sprite::create("Titlebg.png");
	background->setPosition(480, 320);
	background->setScale(1.5f);
	this->addChild(background);

	//魚(青色)画像
	Sprite* fish1 = Sprite::create("fish1.png");
	fish1->setPosition(1000, 0);
	this->addChild(fish1);

	//魚(青色)移動
	MoveTo* fish1move = MoveTo::create(2.0f, Vec2(250, 250));
	fish1->runAction(fish1move);

	//魚(黄色)画像
	Sprite* fish2 = Sprite::create("fish2.png");
	fish2->setPosition(1000, 0);
	this->addChild(fish2);

	//魚(黄色)移動
	MoveTo* fish2move = MoveTo::create(2.0f, Vec2(250, 340));
	fish2->runAction(fish2move);

	//魚(空色)画像
	Sprite* fish3 = Sprite::create("fish3.png");
	fish3->setPosition(1000, 0);
	this->addChild(fish3);

	//魚(空色)移動
	MoveTo* fish3move = MoveTo::create(2.0f, Vec2(110, 300));
	fish3->runAction(fish3move);

	//魚(紫色)画像
	Sprite* fish4 = Sprite::create("fish4.png");
	fish4->setPosition(1000,0);
	this->addChild(fish4);

	//魚(紫色)移動
	MoveTo* fish4move = MoveTo::create(2.0f, Vec2(75, 370));
	fish4->runAction(fish4move);

	// タイトル画像
	Sprite* Title = Sprite::create("Title.png");
	Title->setPosition(500, 520);
	this->addChild(Title);

	//タイトル拡大
	ScaleBy* TitleScale = ScaleBy::create(2.0f, 1.5f);
	Title->runAction(TitleScale);

	//スタートボタン画像
	ui::Button* Start = ui::Button::create("Start.png");
	Start->setPosition(Vec2(510, 180));
	Start->setScale(1.5f);
	this->addChild(Start);

	//Exitボタン画像
	ui::Button* Exit = ui::Button::create("Exit.png");
	Exit->setPosition(Vec2(510, 60));
	Exit->setScale(1.5f);
	this->addChild(Exit);

	// 毎フレーム更新を有効化
	scheduleUpdate();

	// タッチイベントリスナーを作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	Start->addTouchEventListener(CC_CALLBACK_2(TitleScene::onStartClick, this));

	Exit->addTouchEventListener(CC_CALLBACK_2(TitleScene::onExitClick, this));

	// 初期化が正常終了
	return true;
}

// 毎フレーム更新
void TitleScene::update(float delta)
{

}

// タッチ開始時コールバック
bool TitleScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	return false;
}

//Startボタンを押したとき
void TitleScene::onStartClick(Ref* ref, cocos2d::ui::Widget::TouchEventType eventType)
{
	if (eventType == ui::Widget::TouchEventType::ENDED)
	{
		int startse = AudioEngine::play2d("enter.mp3");

		AudioEngine::uncache("titlebgm.mp3");

		// 次のシーンを作成する
		Scene* nextScene = PlayScene::create();

		// 次のシーンに移行
		_director->replaceScene(nextScene);
	}
}

//Exitを押したとき
void TitleScene::onExitClick(Ref * ref, cocos2d::ui::Widget::TouchEventType eventType)
{
	if (eventType == ui::Widget::TouchEventType::ENDED)
	{
		int exitse = AudioEngine::play2d("exit.mp3");

		Sleep(1 * 1000);

		exit(0);
	}
}


