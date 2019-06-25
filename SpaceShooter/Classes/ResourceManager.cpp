#include "ResourceManager.h"
#include <fstream>
#include "iostream"
#include "string"
#include "stdlib.h"
using namespace std;
using namespace ui;
USING_NS_CC;

static ResourceManager *r = nullptr;

ResourceManager* ResourceManager::getInstance()
{
	if (!r)
	{
		r = new  ResourceManager;
	//	r->Init();
	}
	return r;
}

void ResourceManager::Init()
{
	Load();
}

void ResourceManager::Load()
{
	fstream f;
	f.open("Data.bin", ios::in);
	string data;
	int first;
	string second,third, check;
	int i = 0, j=0;
	int check_button=0;
	while (!f.eof())
	{
		i++;
		getline(f, data);
		check = *data.begin();
		if (check == "#")
		{
			i = 0;
			j++;
			continue;
		}
		else if (i == 1)
		{
			data = data.substr(4,1);
			first = stoi(data);
			if (j == 2) check_button++;
		}
		else if (i==2 )
		{
			int pos = data.find_first_of("%s");
			data = data.substr(pos + 2, 100);
			second ="res" + data;
			Sprite* s = Sprite::create(second);
			CC_SAFE_RETAIN(s);
			m_sprites.insert(pair<int, Sprite*>(first, s));

			if (j != 2) {
				i = 0;
			}
			else {
				i = 10000;
				check_button++;
				continue;
			}
			if (j >= 3) {
				Label* label = Label::createWithTTF("",second,20);
				CC_SAFE_RETAIN(label);
				m_labels.insert(pair<int, Label*>(first, label));
			}
		}	
		 if (j == 2 && check_button == 2) {
			int pos_ = data.find_first_of("%s");
			data = data.substr(pos_ + 2, 100);
			third ="res"+ data;
			i = 0;
			check_button = 0;
			ui::Button* button = ui::Button::create(second,third);
			CC_SAFE_RETAIN(button);
			m_buttons.insert(pair<int, Button*>(first, button));
		}
	}
	f.close();
}

Sprite * ResourceManager::GetSpriteById(int id)
{
	map<int, Sprite*>::iterator iter = m_sprites.find(id);
	while(iter!= m_sprites.end())
		return iter->second;
}

ui::Button * ResourceManager::GetButtonById(int id)
{
	map <int, ui::Button*>::iterator iter = m_buttons.find(id);
	return iter->second;
}

Label * ResourceManager::GetLabelById(int id)
{
	map <int, Label*>::iterator iter = m_labels.find(id);
	return iter->second;
}

