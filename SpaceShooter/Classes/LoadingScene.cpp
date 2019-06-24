

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

	background = Sprite::create("background.png");
	background->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background,1);
    
	auto label_hello = ui::TextField::create("HELLO GAME SPACESHOOTER","Arial",10);
	label_hello->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2+ origin.y));
	this->addChild(label_hello,1);


	loadding = Sprite::create("progress.png");
	loadding->setPosition(Point(visibleSize.width / 2 + origin.x , visibleSize.height / 4 + origin.y));
	loadding->setScale(visibleSize.width/400, visibleSize.height/400);
	this->addChild(loadding, 1);

    return true;
}

void LoadingScene::update(float deltaTime)
{

}

