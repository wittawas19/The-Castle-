#pragma once
#include "collider.h"

using namespace sf;
using namespace std;

class bitmap
{
public:
	bitmap(Texture* texture, Vector2f position, Vector2f size);
	~bitmap();

	void draw(RenderWindow& window);
	collider getCollider() { return collider(body); }

private:
	RectangleShape body;
};

