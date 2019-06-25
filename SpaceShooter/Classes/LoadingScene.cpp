
#include "ResourceManager.h"
#include "LoadingScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* LoadingScene::createScene()
{
    return LoadingScene::create();
}


bool LoadingScene::init()
{
  
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	background = ResourceManager::getInstance()->GetSpriteById(0);
	background->retain();
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	background->removeFromParent();
	this->addChild(background,1);
    


    return true;
}

void LoadingScene::update(float deltaTime)
{

}

