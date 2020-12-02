#include "enemy.h"

enemy::enemy(Texture* texture, Vector2u imageCount, Vector2f size, Vector2f position, float switchTime, float speed , int Hp) :
	animation(texture, imageCount, switchTime)
{
	this->HpEnemy = Hp;		
	this->size = size;
	this->position = position;
	this->speed = speed;
	row = 0;

	body.setSize(size);
	body.setPosition(position);
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.f);
}

enemy::~enemy()
{

}

void enemy::updateNpc(float deltaTime, int randomDirection)
{
	Vector2f movement(0.0f, 0.0f);
	this->direction = randomDirection;

	if (direction == 1) // Up
	{
		movement.y -= speed * deltaTime;
	}
	else if (direction == 2) //Down
	{
		movement.y += speed * deltaTime;
	}
	else if (direction == 3) //Left
	{
		movement.x -= speed * deltaTime;
	}
	else if (direction == 4) //Right
	{
		movement.x += speed * deltaTime;
	}
	else
	{
		// No Movement
	}
	body.move(movement);
	animation.update(0, deltaTime);
	body.setTextureRect(animation.uvRect);
	
}

void enemy::updateEnemyFollow(Vector2f enemyPosition, Vector2f playerPosition ,const float deltaTime ,FloatRect weapon )
{
	Vector2f movement;
	Vector2f moveTo;
	movement.x = enemyPosition.x - playerPosition.x;
	movement.y = enemyPosition.y - playerPosition.y;
	float vecLenght = sqrt(pow(movement.x, 2) + pow(movement.y, 2));
	movement /= vecLenght;
	
	// Movement Component
	moveTo.x -= 100.0f * movement.x * deltaTime;
	moveTo.y -= 100.0f * movement.y * deltaTime;

	/*
		this->velocity.x += this->acceleration * x * deltaTime;
		this->velocity.y += this->acceleration * y * deltaTime;
	*/
	if (enemyPosition.x != playerPosition.x)
	{
		
		body.move(moveTo.x, moveTo.y);
	}
	if (body.getGlobalBounds().intersects(weapon))
	{
		HpEnemy = HpEnemy - damage;
	}
	cout << "HpEnemy = " << HpEnemy << endl;
	animation.update(0, deltaTime);
	body.setTextureRect(animation.uvRect);
}



void enemy::draw(RenderWindow& window)
{
	window.draw(body);
}

void enemy::takeDamage(int damage)
{
	this->HpEnemy = HpEnemy - damage; 
}

