#include "SeekEnemy.h"
#include "SeekComponent.h"
#include "SpriteComponent.h"

void SeekEnemy::start()
{
	Actor::start();

	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/player.png")));
	m_seekComponent = dynamic_cast<SeekComponent*>(addComponent(new SeekComponent(m_target)));
}

void SeekEnemy::update(float deltaTime)
{
	Actor::update(deltaTime);
}
