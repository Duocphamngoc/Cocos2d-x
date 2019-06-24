#include "ResourceManager.h"
#include <fstream>
#include "iostream"
#include "string"
using namespace std;
USING_NS_CC;

static ResourceManager *r = nullptr;

ResourceManager* ResourceManager::getInstance()
{
	if (!r)
	{
		r = new (std::nothrow) ResourceManager;
		CCASSERT(r, "FATAL: Not enough memory");
		r->Init();
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
	while (!f.eof())
	{
		getline(f, data);
	}
	f.close();
}

