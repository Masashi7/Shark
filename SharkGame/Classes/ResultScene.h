#pragma once

#include "cocos2d.h"

// タイトルシーン
class ResultScene : public cocos2d::Scene
{
public:
	// create関数の宣言と定義
	//CREATE_FUNC(StaffRollScene);
	static ResultScene* create();

	bool init();

	void update(float delta) override;
};