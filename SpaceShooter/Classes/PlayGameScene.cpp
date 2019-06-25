#include "SimpleAudioEngine.h"
#include "PlayGameScene.h"
#include "ResourceManager.h"
USING_NS_CC;

Scene* PlayGameScene::createScene()
{
	return PlayGameScene::create();
}


bool PlayGameScene::init()
{

	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = ResourceManager::getInstance()->GetSpriteById(0);
	background->retain();
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	background->removeFromParent();
	this->addChild(background, 1);

	auto spaceship = ResourceManager::getInstance()->GetSpriteById(4);
	spaceship->retain();
	spaceship->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	spaceship->removeFromParent();
	this->addChild(spaceship, 1);

	return true;
}

