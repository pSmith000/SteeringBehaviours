#pragma once
#include "Actor.h"

class WanderComponent;
class SpriteComponent;

class WanderEnemy :
	public Actor
{
public:
	WanderEnemy(float distance, float radius, float x, float y, const char* name) : Actor(x, y, name) { m_distance = distance, m_radius = radius; }
	void start() override;
	void update(float deltaTime) override;

private:
	float m_distance;
	float m_radius;
	SpriteComponent* m_spriteComponent;
	WanderComponent* m_wanderComponent;
};

