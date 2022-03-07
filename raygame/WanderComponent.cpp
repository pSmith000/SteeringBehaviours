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
	srand(time(NULL));
	m_distance = distance;
	m_radius = radius;
	m_force = 50;
	m_angle = { 0, 0 };
}


void WanderComponent::update(float deltaTime)
{
	MathLibrary::Vector2 circlePosition = getOwner()->getTransform()->getWorldPosition() + (getOwner()->getTransform()->getForward() * m_distance);

	float randomNumber = (rand() % 400) - 200;
	MathLibrary::Vector2 randPosition = { (float)cos(randomNumber), (float)sin(randomNumber) };


	MathLibrary::Vector2 randomPoint = randPosition.getNormalized() * m_radius;
	randomPoint = randomPoint + circlePosition;


	MathLibrary::Vector2 angle =
		(randomPoint - getOwner()->getTransform()->getWorldPosition()).getNormalized() * m_force;

	m_angle = angle;

	//MoveComponent* moveComponent = dynamic_cast<MoveComponent*>(getOwner()->getComponent("MoveComponent"));

	getOwner()->getTransform()->setForward(m_angle);

	//MathLibrary::Vector2 newVelocity = m_angle - moveComponent->getVelocity();

	//moveComponent->setVelocity(moveComponent->getVelocity() + newVelocity * deltaTime);
}
