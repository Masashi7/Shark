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

// ������
bool ResultScene::init()
{
	// ���N���X�̏�����
	if (!Scene::init())
	{
		// ���N���X�̏����������s�Ȃ�A�ُ�I��
		return false;
	}

	//���̎擾
	int resultbgm = AudioEngine::play2d("resultbgm.mp3");

	AudioEngine::setLoop(resultbgm, true);


	//��ʂ̏c���̃T�C�Y���擾����
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	//�w�i�̉摜���擾
	Sprite* background = Sprite::create("gameover.png");

	//�w�i�̉摜����ʒ����ɕ\��
	background->setPosition(Point(winSize.width / 2, winSize.height / 2));
	//background->setPosition((Vec2(480, 320)));

	//�摜�̃T�C�Y�̒���
	background->setScale(1.4f);

	addChild(background,0);

	//�X�^�[�g�{�^���摜
	ui::Button* resulttitle = ui::Button::create("Restart-button.png");
	resulttitle->setPosition(Point(480, 200));
	resulttitle->setScale(1.0f);
	this->addChild(resulttitle);

	// ���t���[���X�V��L����
	scheduleUpdate();

	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ResultScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	resulttitle->addTouchEventListener(CC_CALLBACK_2(ResultScene::onButtonClick, this));

	// ������������I��
	return true;
}

// �^�b�`�J�n���R�[���o�b�N
bool ResultScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	return false;
}


//�����ŃV�[����ύX�̏ꍇ�i������o�O2��ɂP��̊�������j
void ResultScene::update(float delta)
{
	////���U���g�V�[������^�C�g���V�[����//
	//Scene* nextScene = TitleScene::create();

	////���U���g�V�[������2�b��������u���b�N�A�E�g���ă^�C�g���V�[���֖߂�
	//TransitionFade* fade = TransitionFade::create(10.0f, ResultScene, Color3B::BLACK);
	
	//// ���̃V�[���Ɉڍs
	//_director->replaceScene(nextScene);
	
	////���̃V�[�����폜
	//Director::getInstance()->replaceScene(fade);

}

////�{�^���������ăV�[���ύX
void ResultScene::onButtonClick(Ref* ref, cocos2d::ui::Widget::TouchEventType eventType)
{
	if (eventType == ui::Widget::TouchEventType::ENDED)
	{
		// ���̃V�[�����쐬����
		Scene* nextScene = TitleScene::create();

		// �t�F�[�h�A�E�g�g�����W�V����
		//nextScene = TransitionFade::create(1.0f, nextScene, Color3B(255, 255, 0));
		//nextScene = TransitionOriginal::create(1.0f, nextScene);

		// ���̃V�[���Ɉڍs
		_director->replaceScene(nextScene);
	}
}
