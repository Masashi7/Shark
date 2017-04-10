#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"

// �^�C�g���V�[��
class TitleScene : public cocos2d::Scene
{
public:
	// create�֐��̐錾�ƒ�`
	//CREATE_FUNC(TitleScene);
	static TitleScene* create();

	bool init();

	void update(float delta) override;
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
	void onStartClick(Ref* ref, cocos2d::ui::Widget::TouchEventType eventType);
	void onExitClick(Ref* ref, cocos2d::ui::Widget::TouchEventType eventType);

	cocos2d::Sprite* background = nullptr; //�w�i�摜

	cocos2d::Sprite* Title = nullptr;	   //�^�C�g���摜

	cocos2d::ui::Button* Start =nullptr;   //Start�{�^��

	cocos2d::ui::Button* Exit = nullptr;  //EXit�{�^��

	cocos2d::Sprite* fish1 = nullptr;	  //��(�F)

	cocos2d::Sprite* fish2 = nullptr;	  //��(���F)

	cocos2d::Sprite* fish3 = nullptr;	  //��(��F)

	cocos2d::Sprite* fish4 = nullptr;	  //��(���F)

private:

	int titlebgm;						  //�^�C�g��BGM

};