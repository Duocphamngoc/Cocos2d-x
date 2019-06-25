
#include "ResourceManager.h"
#include "LoadingScene.h"
#include "SimpleAudioEngine.h"
#include "MainMenuScene.h"
#include "PlayGameScene.h"

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
		log("error");
	}
	else{
		logo->setScale(0.3);
		logo->setPosition(Vec2(visibleSize.width/2  + origin.x, visibleSize.height + origin.y-50));
		this->addChild(logo, 1);
	}

	buttonPlay = ResourceManager::getInstance()->GetButtonById(0);
	buttonPlay->removeFromParent();
	if (buttonPlay == nullptr) {
		log("error");
	}
	else {
		buttonPlay->setScale(0.3);
		buttonPlay->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height/2 + origin.y));
		buttonPlay->addTouchEventListener([&](Ref * sender, ui::Widget::TouchEventType type) {
			{
				switch (type)
				{
				case cocos2d::ui::Widget::TouchEventType::BEGAN:
					break;
				
				case cocos2d::ui::Widget::TouchEventType::ENDED:
					this->NextToPlay();
					break;
				default:
					break;
				}
			}
		});
		this->addChild(buttonPlay, 1);


	}


	return true;
}

void MainMenuScene::NextToPlay() {
	auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(PlayGameScene::createScene());
	});

	auto sequence = Sequence::create(gotoNext, nullptr);

	runAction(sequence);
}

