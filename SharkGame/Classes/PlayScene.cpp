#include "PlayScene.h"
#include "ResultScene.h"

USING_NS_CC;

using namespace cocos2d;

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

// ������
bool PlayScene::init()
{
	// ���N���X�̏�����
	if (!Scene::init())
	{
		// ���N���X�̏����������s�Ȃ�A�ُ�I��
		return false;
	}
	
	m_deadNumber = random() % TOOTH_NUM;

	for (int i = 0; i < TOOTH_NUM; i++)
	{
		m_teethFlag[i] = 0;
	}

	CreateSprite();

	// ���t���[���X�V��L����
	scheduleUpdate();
	
	// �^�b�`�C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// ������������I��
	return true;
}

// ���t���[���X�V
void PlayScene::update(float delta)
{
	
}

// �^�b�`�J�n���R�[���o�b�N
bool PlayScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	int i;

	for (i = 0; i < TOOTH_NUM; i++)
	{
		Rect rectSprite;
		Vec2 touchPos = touch->getLocation();
		if (m_pTeeth[i] != nullptr)
		{
			rectSprite = m_pTeeth[i]->getBoundingBox();
		}

		bool hit = rectSprite.containsPoint(touchPos);

		if ((hit == true && i == m_deadNumber))
		{
			FinishGame();
			// ���̃V�[�����쐬����
			Scene* nextScene = ResultScene::create();

			// �t�F�[�h�A�E�g�g�����W�V����
			nextScene = TransitionFade::create(3.0f, nextScene, Color3B(255, 255, 255));

			// ���̃V�[���Ɉڍs
			_director->replaceScene(nextScene);
		}
		else if (hit == true && m_teethFlag[i] != 1)
		{
			ChangeTexter(i);
			break;
		}
	}
	

	return false;
}

// �X�v���C�g�쐬
void PlayScene::CreateSprite()
{
	// �w�i
	m_pBackGround = Sprite::create("sea.png");
	m_pBackGround->setPosition(Vec2(480, 320));
	addChild(m_pBackGround);

	// ��
	m_pTeeth[0] = Sprite::create("tooth_white_1.png");
	m_pTeeth[0]->setPosition(Vec2(299, 160));;

	m_pTeeth[1] = Sprite::create("tooth_white_2.png");
	m_pTeeth[1]->setPosition(Vec2(315, 208));

	m_pTeeth[2] = Sprite::create("tooth_white_3.png");
	m_pTeeth[2]->setPosition(Vec2(335, 262));

	m_pTeeth[3] = Sprite::create("tooth_white_4.png");
	m_pTeeth[3]->setPosition(Vec2(366, 305));

	m_pTeeth[4] = Sprite::create("tooth_white_5.png");
	m_pTeeth[4]->setPosition(Vec2(430, 326));

	m_pTeeth[5] = Sprite::create("tooth_white_6.png");
	m_pTeeth[5]->setPosition(Vec2(504, 326));

	m_pTeeth[6] = Sprite::create("tooth_white_7.png");
	m_pTeeth[6]->setPosition(Vec2(573, 323));

	m_pTeeth[7] = Sprite::create("tooth_white_8.png");
	m_pTeeth[7]->setPosition(Vec2(618, 288));

	m_pTeeth[8] = Sprite::create("tooth_white_9.png");
	m_pTeeth[8]->setPosition(Vec2(636, 253));

	m_pTeeth[9] = Sprite::create("tooth_white_10.png");
	m_pTeeth[9]->setPosition(Vec2(644, 211));

	m_pTeeth[10] = Sprite::create("tooth_white_11.png");
	m_pTeeth[10]->setPosition(Vec2(650, 175));

	m_pTeeth[11] = Sprite::create("tooth_white_12.png");
	m_pTeeth[11]->setPosition(Vec2(322, 102));

	m_pTeeth[12] = Sprite::create("tooth_white_13.png");
	m_pTeeth[12]->setPosition(Vec2(358, 106));

	m_pTeeth[13] = Sprite::create("tooth_white_14.png");
	m_pTeeth[13]->setPosition(Vec2(405, 114));

	m_pTeeth[14] = Sprite::create("tooth_white_15.png");
	m_pTeeth[14]->setPosition(Vec2(453, 126));

	m_pTeeth[15] = Sprite::create("tooth_white_16.png");
	m_pTeeth[15]->setPosition(Vec2(502, 126));

	m_pTeeth[16] = Sprite::create("tooth_white_17.png");
	m_pTeeth[16]->setPosition(Vec2(551, 116));

	m_pTeeth[17] = Sprite::create("tooth_white_18.png");
	m_pTeeth[17]->setPosition(Vec2(596, 108));

	m_pTeeth[18] = Sprite::create("tooth_white_19.png");
	m_pTeeth[18]->setPosition(Vec2(632, 100));

	for (int i = 0; i < TOOTH_NUM; i++)
	{
		addChild(m_pTeeth[i]);
	}

	// �T��
	m_pShark = Sprite::create("Shark_aki.png");
	m_pShark->setPosition(Vec2(480, 320));
	addChild(m_pShark);
}

void PlayScene::ChangeTexter(int texterNumber)
{
	// �e�N�X�`���ύX
	switch (texterNumber)
	{
		case 0:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_1.png");
			break;
		case 1:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_2.png");
			break;
		case 2:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_3.png");
			break;
		case 3:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_4.png");
			break;
		case 4:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_5.png");
			break;
		case 5:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_6.png");
			break;
		case 6:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_7.png");
			break;
		case 7:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_8.png");
			break;
		case 8:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_9.png");
			break;
		case 9:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_10.png");
			break;
		case 10:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_11.png");
			break;
		case 11:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_12.png");
			break;
		case 12:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_13.png");
			break;
		case 13:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_14.png");
			break;
		case 14:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_15.png");
			break;
		case 15:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_16.png");
			break;
		case 16:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_17.png");
			break;
		case 17:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_18.png");
			break;
		case 18:
			m_pTeeth[texterNumber]->setTexture("Tooth_red_19.png");
			break;
	}

	m_teethFlag[texterNumber] = 1;
}

void PlayScene::FinishGame()
{
	for (int i = 0; i < 19; i++)
	{
		m_pTeeth[i]->removeFromParent();
	}

	m_pShark->setTexture("Shark_toji.png");
	m_pShark->setPosition(Vec2(480, 210));
}