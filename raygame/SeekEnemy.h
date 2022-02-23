#pragma once
#include "Actor.h"

class SeekComponent;
class SpriteComponent;

class SeekEnemy :
	public Actor
{
public:
	SeekEnemy(Actor* target, float x, float y, const char* name) : Actor(x, y, name) { m_target = target; }
	void start() override;
	void update(float deltaTime) override;

private:
	Actor* m_target;
	SpriteComponent* m_spriteComponent;
	SeekComponent* m_seekComponent;
};

