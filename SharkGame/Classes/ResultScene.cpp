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

// ������
bool ResultScene::init()
{
	// ���N���X�̏�����
	if (!Scene::init())
	{
		// ���N���X�̏����������s�Ȃ�A�ُ�I��
		return false;
	}
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("gameover.png");

	background->setPosition(Point(winSize.width / 2, winSize.height / 2));

	this->addChild(background,0);

	// ���t���[���X�V��L����
	scheduleUpdate();

	// ������������I��
	return true;
}

// ���t���[���X�V
void ResultScene::update(float delta)
{
	
	Scene* nextScene = TitleScene::create();

	TransitionFade* fade = TransitionFade::create(2.0f, nextScene, Color3B::BLACK);
	
	// ���̃V�[���Ɉڍs
	//_director->replaceScene(nextScene);
	Director::getInstance()->replaceScene(fade);

}