#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"

// タイトルシーン
class TitleScene : public cocos2d::Scene
{
public:
	// create関数の宣言と定義
	//CREATE_FUNC(TitleScene);
	static TitleScene* create();

	bool init();

	void update(float delta) override;
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
	void onStartClick(Ref* ref, cocos2d::ui::Widget::TouchEventType eventType);
	void onExitClick(Ref* ref, cocos2d::ui::Widget::TouchEventType eventType);

	cocos2d::Sprite* background = nullptr; //背景画像

	cocos2d::Sprite* Title = nullptr;	   //タイトル画像

	cocos2d::ui::Button* Start =nullptr;   //Startボタン

	cocos2d::ui::Button* Exit = nullptr;  //EXitボタン

	cocos2d::Sprite* fish1 = nullptr;	  //魚(青色)

	cocos2d::Sprite* fish2 = nullptr;	  //魚(黄色)

	cocos2d::Sprite* fish3 = nullptr;	  //魚(空色)

	cocos2d::Sprite* fish4 = nullptr;	  //魚(紫色)

private:

	int titlebgm;						  //タイトルBGM

};