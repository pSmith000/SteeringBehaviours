#include "SeekComponent.h"
#include "Transform2D.h"
#include "Agent.h"
#include "Actor.h"
#include "MoveComponent.h"

MathLibrary::Vector2 SeekComponent::calculateForce()
{
	if (!getTarget())
		return { 0, 0 };

	MathLibrary::Vector2 directionToTarget = MathLibrary::Vector2::normalize(getTarget()->getTransform()->getWorldPosition() 
		- getOwner()->getTransform()->getWorldPosition());

	MathLibrary::Vector2 desiredVelocity = directionToTarget * getSteeringForce();

	MathLibrary::Vector2 seekForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();
	return seekForce;

}

SeekComponent::SeekComponent(Actor* target, const char* name) : Component::Component(name)
{
	m_actorTarget = target;
	m_maxSpeed = 500;
	m_seekForce = 500;
	m_currentVelocity = MathLibrary::Vector2{ 0, 0 };
	hasActor = true;
}

SeekComponent::SeekComponent(MathLibrary::Vector2 position, const char* name)
{
	m_target = position;
	m_maxSpeed = 500;
	m_seekForce = 500;
	m_currentVelocity = MathLibrary::Vector2{ 0, 0 };
	hasActor = false;
}

void SeekComponent::update(float deltaTime)
{
	if (hasActor)
		m_desiredVelocity = (getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition()).getNormalized() * m_seekForce;
	else
		m_desiredVelocity = (m_target - getOwner()->getTransform()->getWorldPosition()).getNormalized() * m_seekForce;

	getOwner()->getTransform()->setForward(m_currentVelocity);

	m_steeringForce = m_desiredVelocity - m_currentVelocity;

	m_currentVelocity = m_currentVelocity + (m_steeringForce * deltaTime);

	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getWorldPosition();

	newPosition = newPosition + (m_currentVelocity * deltaTime);

	getOwner()->getTransform()->setWorldPostion(newPosition);
}
