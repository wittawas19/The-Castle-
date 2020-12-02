#pragma once
#include "animation.h"
#include "collider.h"
#include "movementComponent.h"
#include "weapon.h"
#include <iostream>
using namespace sf;
using namespace std;

class enemy : public movementComponent
{
public :
	enemy(Texture* texture, Vector2u imageCount, Vector2f size, Vector2f position,float switchTime, float speed ,int Hp );
	~enemy();

	int direction = -1;
	int damage = 10; 
	void updateNpc(float deltaTime , int randomDirection);
	void updateEnemyFollow(Vector2f enemyPosition, Vector2f playerPosition , const float deltaTime,FloatRect weapon);
	void draw(RenderWindow& window);
	void setPosition(sf::Vector2f(xy)) { body.setPosition(xy); };
	inline const int getDamage()const { return damage; };
	void takeDamage(int damage);
	sf::FloatRect getGlobals() { return body.getGlobalBounds(); }
	Vector2f getPosition() { return body.getPosition(); }
	collider getCollider() { return collider(body); }

private :

	float acceleration = 1.0f;
	sf::Vector2f velocity;
	RectangleShape body;
	animation animation;
	Vector2f size;
	Vector2f position;
	unsigned int row;
	float speed = 20;
	int randomDirection = 5;
	int HpEnemy; 
};

