
#include "ResourceManager.h"
#include "LoadingScene.h"
#include "SimpleAudioEngine.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
	return MainMenuScene::create();
}


bool MainMenuScene::init()
{

	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	logo = ResourceManager::getInstance()->GetSpriteById(1);
	logo->removeFromParent();
	if (logo == nullptr) {
		log("ddadsas");
	}
	else{
		logo->setScale(0.3);
		logo->setPosition(Vec2(visibleSize.width/2  + origin.x, visibleSize.height + origin.y-50));
		this->addChild(logo, 1);
	}

	buttonPlay = ResourceManager::getInstance()->GetButtonById(0);
	buttonPlay->removeFromParent();
	if (logo == nullptr) {
		log("ddadsas");
	}
	else {
		buttonPlay->setScale(0.3);
		buttonPlay->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height/2 + origin.y));
		this->addChild(buttonPlay, 1);
	}
	return true;
}


