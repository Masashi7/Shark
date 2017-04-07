#include "PlayScene.h"
#include "TitleScene.h"
#include "ResultScene.h"

USING_NS_CC;

PlayScene* PlayScene::create()
{
	PlayScene *pRet = new(std::nothrow) PlayScene();
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
bool PlayScene::init()
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
	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// 初期化が正常終了
	return true;
}

// 毎フレーム更新
void PlayScene::update(float delta)
{
	// 次のシーンを作成する
	Scene* nextScene = StaffRollScene::create();
	// 次のシーンに移行
	_director->replaceScene(nextScene);
}

// タッチ開始時コールバック
bool PlayScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	// 次のシーンを作成する
	Scene* nextScene = ResultScene::create();

	// 次のシーンに移行
	_director->replaceScene(nextScene);

	return true;
}
