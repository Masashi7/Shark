#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"

// ^CgV[
class TitleScene : public cocos2d::Scene
{
public:
	// createΦΜιΎΖθ`
	//CREATE_FUNC(TitleScene);
	static TitleScene* create();

	bool init();

	void update(float delta) override;
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
	void onButtonClick(Ref* ref ,cocos2d::ui::Widget::TouchEventType eventType);

	cocos2d::Sprite* background = nullptr; //wiζ

	cocos2d::Sprite* Title = nullptr;	   //^Cgζ

	cocos2d::ui::Button* Start =nullptr;   //Start{^

	cocos2d::ui::Button* Exit = nullptr;  //EXit{^

	cocos2d::Sprite* fish1 = nullptr;	  //(ΒF)

	cocos2d::Sprite* fish2 = nullptr;	  //(©F)

	cocos2d::Sprite* fish3 = nullptr;	  //(σF)

	cocos2d::Sprite* fish4 = nullptr;	  //(F)

};