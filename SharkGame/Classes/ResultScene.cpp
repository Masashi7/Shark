#include "TitleScene.h"
#include "ResultScene.h"
#include "AudioEngine.h"

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

	// 毎フレーム更新を有効化
	scheduleUpdate();

	// 初期化が正常終了
	return true;
}

// 毎フレーム更新
void ResultScene::update(float delta)
{

}