#include "BooleanDecision.h"

BooleanDecision::BooleanDecision(Decision* leftChild, Decision* rightChild)
{
	m_left = leftChild;
	m_right = rightChild;
}

void BooleanDecision::makeDecision(Agent* agent, float deltaTime)
{
	if (checkCondition(agent, deltaTime))
		if (m_left)
		{
			m_left->makeDecision(agent, deltaTime);
		}
	else
		if (m_right)
		{
			m_right->makeDecision(agent, deltaTime);
		}
			
}
