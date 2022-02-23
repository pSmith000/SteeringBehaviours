#include "SeekComponent.h"
#include "Transform2D.h"
#include "Actor.h"

SeekComponent::SeekComponent(Actor* target, const char* name) : Component::Component(name)
{
	m_target = target;
	m_maxSpeed = 500;
	m_seekForce = 500;
	m_currentVelocity = MathLibrary::Vector2{ 0, 0 };
}

void SeekComponent::update(float deltaTime)
{
	m_desiredVelocity = (getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition()).getNormalized() * m_seekForce;

	m_steeringForce = m_desiredVelocity - m_currentVelocity;

	m_currentVelocity = m_currentVelocity + (m_steeringForce * deltaTime);

	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getWorldPosition();

	newPosition = newPosition + (m_currentVelocity * deltaTime);

	getOwner()->getTransform()->setWorldPostion(newPosition);
}
