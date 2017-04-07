#pragma once

#include "cocos2d.h"

// タイトルシーン
class PlayScene : public cocos2d::Scene
{
public:
	// create関数の宣言と定義
	/*CREATE_FUNC(PlayScene);*/
	static PlayScene* create();

	bool init();

	void update(float delta) override;
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
};