#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"

// タイトルシーン
class ResultScene : public cocos2d::Scene
{
private:
	
	cocos2d::Sprite* background;

public:
	// create関数の宣言と定義
	//CREATE_FUNC(StaffRollScene);
	static ResultScene* create();

	bool init();

	void update(float delta) override;

	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
	void onButtonClick(Ref* ref ,cocos2d::ui::Widget::TouchEventType eventType);
	cocos2d::ui::Button* button; //ボタン

	cocos2d::ui::Button* resulttitle = nullptr;  //EXitボタン

	
	cocos2d::Sprite* sprite = nullptr;
};