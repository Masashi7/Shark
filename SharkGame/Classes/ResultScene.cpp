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
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("gameover.png");

	background->setPosition(Point(winSize.width / 2, winSize.height / 2));

	this->addChild(background,0);

	// 毎フレーム更新を有効化
	scheduleUpdate();

	// 初期化が正常終了
	return true;
}

// 毎フレーム更新
void ResultScene::update(float delta)
{
	
	Scene* nextScene = TitleScene::create();

	TransitionFade* fade = TransitionFade::create(2.0f, nextScene, Color3B::BLACK);
	
	// 次のシーンに移行
	//_director->replaceScene(nextScene);
	Director::getInstance()->replaceScene(fade);

}