#pragma once
#include "animation.h"
#include "collider.h"
#include <iostream>
#include "weapon.h"


using namespace sf;
using namespace std;

class player
{
public:
	char direction = '.';
	player(Texture* texture, Vector2u imageCount, float switchTime, float speed, int Hp ,int damage);
	~player();
	bool isAtk = true;
	int damage = 10; 
	void update(float deltaTime , weapon *weapon);
	void draw(RenderWindow& window);
	void setPosition(sf::Vector2f(xy)) { body.setPosition(xy); };
	void setSize(sf::Vector2f(x)) { body.setSize(x); };
	inline int getDamage() { return this->damage; }; 
	void takeDamage( int damage );
	int updateAtk(weapon* weapon ,Vector2f position ,FloatRect enemy ,int damage);

	
	//void getPosition(sf::Vector2f(xy)) {}
	sf::FloatRect getGlobals() { return body.getGlobalBounds(); };
	Vector2f getSize() { body.getSize(); };
	Vector2f getPosition() { return body.getPosition(); }
	collider getCollider() { return collider(body); }

private:
	RectangleShape body;
	animation animation;
	unsigned int row;
	float speed;
	int HpPlayer ;
};