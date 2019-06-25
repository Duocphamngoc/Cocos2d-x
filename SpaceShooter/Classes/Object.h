#pragma once
#include "cocos2d.h"
USING_NS_CC;
class MObject {
protected:
	Sprite* m_sprite;
public:
	MObject();
	~MObject();
	virtual void Update()=0;
	virtual void Init()=0;
};
