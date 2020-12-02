#pragma once
#include "collider.h"


using namespace sf;
using namespace std;

class projectile
{
public:
	projectile(Texture* texture, float speed, float attackDamage);

	char direction = '.'; //1-up, 2-down, 3-left, 4-right//
	RectangleShape body;

	void update(float deltaTime);
	collider getCollider() { return collider(body); }

private:
	float speed;
	float atkdmg;
};

