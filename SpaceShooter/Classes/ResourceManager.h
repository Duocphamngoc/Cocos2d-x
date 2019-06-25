#pragma once
#include "cocos2d.h"
#include "string"
#include <map>
#include "ui/CocosGUI.h"

USING_NS_CC;

class ResourceManager {
private:
	char* m_dataFolderPath;
	std::map <int, Sprite*> m_sprites;
	std::map <int, ui::Button*> m_buttons;
	std::map <int, Label*> m_labels;
public: 
	static ResourceManager* getInstance();
	void Init();
	void Load();
	Sprite* GetSpriteById();
	ui::Button* GetButtonById();
	Label* GetLabelById();
};