#pragma once
#include "Component.h"


enum State
{
	IDLE,
	WANDER,
	SEEK
};

class SeekComponent;
class WanderComponent;

class StateMachineComponent :
	public Component
{
public:
	State getCurrentState() { return m_currentState; }
	void setCurrentState(State state) { m_currentState = state; }

	void start() override;
	void update(float deltaTime) override;

private:
	State m_currentState;
	SeekComponent* m_seekComponent;
	WanderComponent* m_wanderComponent;
	float m_seekForce;
	float m_wanderForce;
	float m_seekRange = 200;
};

