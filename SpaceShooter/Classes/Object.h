#pragma once
#include "cocos2d.h"
USING_NS_CC;
class Object {
private:
	Sprite* m_sprite;
public:
	Object();
	~Object();
	virtual void Update()=0;
	virtual void Init()=0;
};