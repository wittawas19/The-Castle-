#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;
using namespace std;
class collider
{
public:
	collider(RectangleShape& body);
	~collider();
	 void Move(const float x, const float y, const float& deltaTime)
	{
		this->velocity.x += this->acceleration * x * deltaTime;
		this->velocity.y += this->acceleration * y * deltaTime;
	}
	void move(float dx, float dy) { body.move(dx, dy); }

	bool checkCollider(collider other, float push);
	bool checkintersects(collider other);
	Vector2f getPosition() { return body.getPosition(); }
	Vector2f getHalfSize() { return body.getSize() / 2.0f; }
	Vector2f getSize() { return body.getSize(); };

private:
	RectangleShape& body;
	float acceleration = 1.0f;
	sf::Vector2f velocity;
};
