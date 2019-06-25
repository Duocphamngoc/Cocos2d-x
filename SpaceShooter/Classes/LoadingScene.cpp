
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

	loading = ResourceManager::getInstance()->GetSpriteById(6);
	loading->retain();
	loading->setScale(visibleSize.width*0.0008, visibleSize.height*0.002);
	loading->setPosition(Vec2(visibleSize.width / 2 + origin.x -100, visibleSize.height / 4 + origin.y));
	loading->removeFromParent();
	this->addChild(loading, 1);

	label = ResourceManager::getInstance()->GetLabelById(1);
	if (label==nullptr) {
		log("error");
	}
	else {
		label->setString("LOADING....!");
		label->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height /3 + origin.y));
		this->addChild(label,1);
	}
	this-> update(3);
	this->scheduleUpdate();

    return true;
}

void LoadingScene::update(float deltaTime)
{
	float x = LoadingScene::loading->getScaleX();
	x = x + 0.008;
	LoadingScene::loading->setScaleX(x);

	if (x >= 1.6) {
		this->unscheduleUpdate();
		auto gotoNext = CallFunc::create([]() {
			Director::getInstance()->replaceScene(MainMenuScene::createScene());
			});

		auto sequence = Sequence::create( gotoNext, nullptr);

		runAction(sequence);
	}
	
	 
}

