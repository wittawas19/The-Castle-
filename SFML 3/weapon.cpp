#include "weapon.h"

weapon::weapon(sf::Texture* texture ,Vector2u imageCount , float switchTime, sf::Vector2f position ):
	animation(texture, imageCount, switchTime)
{
	this->position = position;
	
	//this->direction.x = dir_X;
	//this->direction.y = dir_Y;
	//this->movementSpeed = movement_speed;
	body.setSize(Vector2f(300.0f,300.0f));
	body.setPosition(position); 
	body.setTexture(texture);
	body.setOrigin(body.getSize()/ 2.0f);
	
}

weapon::~weapon()
{
}

const sf::FloatRect weapon::getBounds() const
{
	return this->body.getGlobalBounds();
}

void weapon::update(float deltaTime ,Vector2f positionPlayer)
{
	//this->shape.move(this->movementSpeed * this->direction);
	setPositon(positionPlayer);
	animation.update(0, deltaTime);
	body.setTextureRect(animation.uvRect);
}


