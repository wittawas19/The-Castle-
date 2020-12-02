#include "movementComponent.h"

void movementComponent::Move(const float x, const float y, const float& deltaTime)
{
	this->velocity.x += this->acceleration * x * deltaTime;
	this->velocity.y += this->acceleration * y * deltaTime;
}
