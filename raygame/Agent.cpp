#include "Agent.h"
#include "MoveComponent.h"
#include "SteeringComponent.h"

void Agent::start()
{
	m_moveComponent = addComponent<MoveComponent>();
}

void Agent::update(float deltaTime)
{
	for (int i = 0; i < m_steeringComponents.getLength(); i++)
	{
		m_force = m_force + m_steeringComponents[i]->calculateForce();
	}

	if (m_force.getMagnitude() > getMaxForce())
	{
		m_force = m_force.getNormalized() * getMaxForce();
	}
}
