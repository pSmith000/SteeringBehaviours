#pragma once
#include "Actor.h"

class FleeComponent;
class SpriteComponent;

class FleeEnemy :
	public Actor
{
public:
	FleeEnemy(Actor* target, float x, float y, const char* name) : Actor(x, y, name) { m_target = target; }
	void start() override;
	void update(float deltaTime) override;

private:
	Actor* m_target;
	SpriteComponent* m_spriteComponent;
	FleeComponent* m_fleeComponent;
};

