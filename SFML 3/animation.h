#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class animation
{
public:
	animation(Texture* texture, Vector2u imageCount, float switchTime);
	~animation();

	void update(int row, float deltaTime);

	IntRect uvRect;

private:
	Vector2u imageCount;
	Vector2u currentImage;

	float totalTime;
	float switchTime;
};

