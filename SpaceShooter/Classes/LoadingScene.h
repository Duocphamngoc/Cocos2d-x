

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class LoadingScene : public cocos2d::Scene
{
private:
	Sprite* background;
	Sprite* loadding;
	
	
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(LoadingScene);
};

#endif 
