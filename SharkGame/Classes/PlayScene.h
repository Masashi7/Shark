#pragma once

#include "cocos2d.h"
#include "audio\include\AudioEngine.h"

#define TOOTH_NUM 19	//歯の数

// タイトルシーン
class PlayScene : public cocos2d::Scene
{
	protected:
		cocos2d::Sprite* m_pTeeth[TOOTH_NUM];
		cocos2d::Sprite* m_pBackGround;
		cocos2d::Sprite* m_pShark;

		int m_deadNumber = 0;
		int m_teethFlag[TOOTH_NUM];

	public:
		// create関数の宣言と定義
		/*CREATE_FUNC(PlayScene);*/
		static PlayScene* create();

		bool init();
		void update(float delta) override;

		bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);

		void CreateSprite();
		void ChangeTexter(int texterNumber);
};