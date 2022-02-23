#include "WanderEnemy.h"
#include "WanderComponent.h"
#include "SpriteComponent.h"

void WanderEnemy::start()
{
	Actor::start();

	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/player.png")));
	m_wanderComponent = dynamic_cast<WanderComponent*>(addComponent(new WanderComponent(m_distance, m_radius)));
}

void WanderEnemy::update(float deltaTime)
{
	Actor::update(deltaTime);
}
