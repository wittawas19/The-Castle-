#pragma once
#include "SFML/Graphics.hpp"

class movementComponent
{
public :

	void Move(const float x, const float y, const float& deltaTime);
private :
	
	float acceleration = 1.0f;


	sf::Vector2f velocity;

};

