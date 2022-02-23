#include "WanderComponent.h"
#include "Transform2D.h"
#include "Actor.h"
#include <stdlib.h> 
#include <time.h>    
#include <Vector2.h>

WanderComponent::WanderComponent(float distance, float radius, const char* name) : Component :: Component(name)
{
	m_distance = distance;
	m_radius = radius;
}

void WanderComponent::start()
{
	srand(time(NULL));
	m_randomValue = (rand() % 200) - 100;
}

void WanderComponent::update(float deltaTime)
{
	m_position = getOwner()->getTransform()->getWorldPosition() * m_distance;
	m_position = m_position.getNormalized();
	getOwner()->getTransform()->setWorldPostion(m_position * m_radius);
}
