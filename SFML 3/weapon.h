#pragma once
#include "SFML/Graphics.hpp"
#include "collider.h"
#include <iostream>
#include "animation.h"

class weapon
{

public:
	//bullet functions
	weapon(sf::Texture* texture, Vector2u imageCount,  float switchTime , Vector2f position);
	virtual ~weapon();

	//getBounds functions
	const sf::FloatRect getBounds() const;

	//render and update functions
	void update(float deltaTime ,Vector2f positionPlayer);


	//bullet status
	//sf::Vector2f direction;
	//float movementSpeed;
	//Position 
	void setPositon(Vector2f xy) { return body.setPosition(xy); };
	void draw(RenderWindow& window) { window.draw(body); }; 


private:
	Vector2f size; 
	RectangleShape body; 
	animation animation;
	Vector2f position; 
};

