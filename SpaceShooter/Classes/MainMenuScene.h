#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class MainMenuScene : public cocos2d::Scene
{
private:
	Sprite* logo;
	ui::Button* buttonPlay;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();


	CREATE_FUNC(MainMenuScene);
};
