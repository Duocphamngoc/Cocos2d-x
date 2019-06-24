#pragma once
#include "cocos2d.h"
#include "string"
#include <map>
#include "ui/CocosGUI.h"
using namespace ui;
USING_NS_CC;

class ResourceManager {
private:
	char* m_dataFolderPath;
	char* m_sprites;
	char* m_buttons;
	char* m_labels;
public: 
	static ResourceManager* getInstance();
	void Init();
	void Load();
	Sprite* GetSpriteById();
	Button* GetButtonById();
	Label* GetLabelById();
};