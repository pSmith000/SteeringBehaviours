#pragma once
#include "Component.h"
#include <Vector2.h>

class FleeComponent :
	public Component
{

public:
	FleeComponent(Actor* target, const char* name = "Flee Component");

	Actor* getTarget() { return m_target; }

	void setTarget(Actor* target) { m_target = target; }

	void update(float deltaTime) override;

private:
	Actor* m_target;
	MathLibrary::Vector2 m_currentVelocity;
	MathLibrary::Vector2 m_steeringForce;
	MathLibrary::Vector2 m_desiredVelocity;
	float m_maxSpeed;
};

