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

// ������
bool TitleScene::init()
{
	// ���N���X�̏�����
	if (!Scene::init())
	{
		// ���N���X�̏����������s�Ȃ�A�ُ�I��
		return false;
	}

	//BGM�Đ�
	titlebgm = AudioEngine::play2d("titlebgm.mp3");
	
	//���[�v�Đ�
	AudioEngine::setLoop(titlebgm, true);

	// �w�i�摜
	Sprite* background = Sprite::create("Titlebg.png");
	background->setPosition(480, 320);
	background->setScale(1.5f);
	this->addChild(background);

	//��(�F)�摜
	Sprite* fish1 = Sprite::create("fish1.png");
	fish1->setPosition(1000, 0);
	this->addChild(fish1);

	//��(�F)�ړ�
	MoveTo* fish1move = MoveTo::create(2.0f, Vec2(250, 250));
	fish1->runAction(fish1move);

	//��(���F)�摜
	Sprite* fish2 = Sprite::create("fish2.png");
	fish2->setPosition(1000, 0);
	this->addChild(fish2);

	//��(���F)�ړ�
	MoveTo* fish2move = MoveTo::create(2.0f, Vec2(250, 340));
	fish2->runAction(fish2move);

	//��(��F)�摜
	Sprite* fish3 = Sprite::create("fish3.png");
	fish3->setPosition(1000, 0);
	this->addChild(fish3);

	//��(��F)�ړ�
	MoveTo* fish3move = MoveTo::create(2.0f, Vec2(110, 300));
	fish3->runAction(fish3move);

	//��(���F)�摜
	Sprite* fish4 = Sprite::create("fish4.png");
	fish4->setPosition(1000,0);
	this->addChild(fish4);

	//��(���F)�ړ�
	MoveTo* fish4move = MoveTo::create(2.0f, Vec2(75, 370));
	fish4->runAction(fish4move);

	// �^�C�g���摜
	Sprite* Title = Sprite::create("Title.png");
	Title->setPosition(500, 520);
	this->addChild(Title);

	//�^�C�g���g��
	ScaleBy* TitleScale = ScaleBy::create(2.0f, 1.5f);
	Title->runAction(TitleScale);

	//�X�^�[�g�{�^���摜
	ui::Button* Start = ui::Button::create("Start.png");
	Start->setPosition(Vec2(510, 180));
	Start->setScale(1.5f);
	this->addChild(Start);

	//Exit�{�^���摜
	ui::Button* Exit = ui::Button::create("Exit.png");
	Exit->setPosition(Vec2(510, 60));
	Exit->setScale(1.5f);
	this->addChild(Exit);

	// ���t���[���X�V��L����
	scheduleUpdate();

	// �^�b�`�C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	Start->addTouchEventListener(CC_CALLBACK_2(TitleScene::onStartClick, this));

	Exit->addTouchEventListener(CC_CALLBACK_2(TitleScene::onExitClick, this));

	// ������������I��
	return true;
}

// ���t���[���X�V
void TitleScene::update(float delta)
{

}

// �^�b�`�J�n���R�[���o�b�N
bool TitleScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	return false;
}

//Start�{�^�����������Ƃ�
void TitleScene::onStartClick(Ref* ref, cocos2d::ui::Widget::TouchEventType eventType)
{
	if (eventType == ui::Widget::TouchEventType::ENDED)
	{
		int startse = AudioEngine::play2d("enter.mp3");

		AudioEngine::uncache("titlebgm.mp3");

		// ���̃V�[�����쐬����
		Scene* nextScene = PlayScene::create();

		// ���̃V�[���Ɉڍs
		_director->replaceScene(nextScene);
	}
}

//Exit���������Ƃ�
void TitleScene::onExitClick(Ref * ref, cocos2d::ui::Widget::TouchEventType eventType)
{
	if (eventType == ui::Widget::TouchEventType::ENDED)
	{
		int exitse = AudioEngine::play2d("exit.mp3");

		Sleep(1 * 1000);

		exit(0);
	}
}


