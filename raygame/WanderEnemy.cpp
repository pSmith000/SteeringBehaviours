#include "WanderEnemy.h"
#include "WanderComponent.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"

void WanderEnemy::start()
{
	Actor::start();

	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/player.png")));
	m_wanderComponent = dynamic_cast<WanderComponent*>(addComponent(new WanderComponent(m_distance, m_radius)));
	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
}

void WanderEnemy::update(float deltaTime)
{
	Actor::update(deltaTime);
}
