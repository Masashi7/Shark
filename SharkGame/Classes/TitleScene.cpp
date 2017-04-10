#include "TitleScene.h"
#include "PlayScene.h"

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

	// �w�i�摜
	Sprite* background = Sprite::create("Titlebg.png");
	background->setPosition(480, 320);
	this->addChild(background);

	// �^�C�g���摜
	Sprite* Title = Sprite::create("Title.png");
	Title->setPosition(480, 0);
	this->addChild(Title);

	//�X�^�[�g�{�^���摜
	ui::Button* Start = ui::Button::create("Start.png");
	Start->setPosition(Vec2(480, 100));
	this->addChild(Start);

	//Exit�{�^���摜
	ui::Button* Exit = ui::Button::create("Exit.png");
	Exit->setPosition(Vec2(480, 50));
	this->addChild(Exit);

	// ���t���[���X�V��L����
	scheduleUpdate();

	// �^�b�`�C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	button->addTouchEventListener(CC_CALLBACK_2(TitleScene::onButtonClick, this));

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

void TitleScene::onButtonClick(Ref* ref, cocos2d::ui::Widget::TouchEventType eventType)
{
	if (eventType == ui::Widget::TouchEventType::ENDED)
	{
		// ���̃V�[�����쐬����
		Scene* nextScene = PlayScene::create();

		// �t�F�[�h�A�E�g�g�����W�V����
		//nextScene = TransitionFade::create(1.0f, nextScene, Color3B(255, 255, 0));
		//nextScene = TransitionOriginal::create(1.0f, nextScene);

		// ���̃V�[���Ɉڍs
		_director->replaceScene(nextScene);
	}
}
