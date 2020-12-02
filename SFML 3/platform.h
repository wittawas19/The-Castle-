#pragma once
#include "collider.h"

using namespace sf;
using namespace std;

class platform
{
public:
	platform(Texture* texture, Vector2f size, Vector2f position);
	~platform();

	void draw(RenderWindow& window);
	collider getCollider() { return collider(body); }

private:
	RectangleShape body;
};
