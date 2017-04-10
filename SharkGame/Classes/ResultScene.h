#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"

// �^�C�g���V�[��
class ResultScene : public cocos2d::Scene
{
private:
	
	cocos2d::Sprite* background;

public:
	// create�֐��̐錾�ƒ�`
	//CREATE_FUNC(StaffRollScene);
	static ResultScene* create();

	bool init();

	void update(float delta) override;

	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
	void onButtonClick(Ref* ref ,cocos2d::ui::Widget::TouchEventType eventType);
	cocos2d::ui::Button* button; //�{�^��

	cocos2d::ui::Button* resulttitle = nullptr;  //EXit�{�^��

	
	cocos2d::Sprite* sprite = nullptr;
};