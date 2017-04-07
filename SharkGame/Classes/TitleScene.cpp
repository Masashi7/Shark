#include "TitleScene.h"
#include "PlayScene.h"

#include "ui/CocosGUI.h"

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

	// 毎フレーム更新を有効化
	scheduleUpdate();

	// タッチイベントリスナーを作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

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

void TitleScene::onButtonClick(Ref* ref)
{
	// 次のシーンを作成する
	Scene* nextScene = PlayScene::create();
	// フェードアウトトランジション
	//nextScene = TransitionFade::create(1.0f, nextScene, Color3B(255, 255, 0));
	//nextScene = TransitionOriginal::create(1.0f, nextScene);
	// 次のシーンに移行
	_director->replaceScene(nextScene);
}
