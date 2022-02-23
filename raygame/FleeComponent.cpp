#include "FleeComponent.h"
#include "Transform2D.h"
#include "Actor.h"

FleeComponent::FleeComponent(Actor* target, const char* name) : Component::Component(name)
{
	m_target = target;
	m_maxSpeed = 300;
	m_currentVelocity = MathLibrary::Vector2{ 0, 0 };
}

void FleeComponent::update(float deltaTime)
{
	//setTarget(m_target);

	m_desiredVelocity = (getOwner()->getTransform()->getLocalPosition() - getTarget()->getTransform()->getLocalPosition()).getNormalized() * m_maxSpeed;

	m_steeringForce = m_desiredVelocity - m_currentVelocity;

	m_currentVelocity = m_currentVelocity + (m_steeringForce * deltaTime);

	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getLocalPosition();

	newPosition = newPosition + (m_currentVelocity * deltaTime);

	getOwner()->getTransform()->setLocalPosition(newPosition);
}
