#pragma once
#include "Object.h"
using namespace std;

class SpaceShooter : public MObject {


public:
	void Update() override;
	void Shoot();
	void Collision();

};