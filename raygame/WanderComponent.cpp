#include "WanderComponent.h"
#include "Transform2D.h"
#include "Actor.h"
#include "MoveComponent.h"
#include <stdlib.h> 
#include <time.h>    
#include <Vector2.h>
#include <math.h>

WanderComponent::WanderComponent(float distance, float radius, const char* name) : Component :: Component(name)
{
	m_distance = distance;
	m_radius = radius;
	m_force = 200;
	m_angle = { 0, 0 };
}

void WanderComponent::start()
{
	srand(time(NULL));
}

void WanderComponent::update(float deltaTime)
{
	MathLibrary::Vector2 randomVector = { (float)((rand() % 200)), (float)((rand() % 200)) };

	//MathLibrary::Vector2 randomPoint = { (float)(cos(randomVector.x), (float)sin(randomVector.y)) };

	MathLibrary::Vector2 circlePosition = getOwner()->getTransform()->getWorldPosition() + (getOwner()->getTransform()->getForward() * m_distance);

	//randomPoint = randomPoint + circlePosition;

	//MathLibrary::Vector2 angle =(randomPoint - getOwner()->getTransform()->getWorldPosition()).getNormalized() * m_force;

	//m_angle = angle;


}
