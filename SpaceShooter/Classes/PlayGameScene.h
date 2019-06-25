#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class PlayGameScene : public cocos2d::Scene
{
private:
	

public:
	static cocos2d::Scene* createScene();

	virtual bool init();


	CREATE_FUNC(PlayGameScene);
};
