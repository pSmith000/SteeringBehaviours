#pragma once
#include "Component.h"
#include <Vector2.h>
class SeekComponent :
	public Component
{
public:
	SeekComponent(Actor* target, const char* name = "Seek Component");

	Actor* getTarget() { return m_target; }

	void setTarget(Actor* target) { m_target = target; }

	void setSpeed(float speed) { m_maxSpeed = speed; }

	void update(float deltaTime) override;

private:
	Actor* m_target;
	MathLibrary::Vector2 m_currentVelocity;
	MathLibrary::Vector2 m_steeringForce;
	MathLibrary::Vector2 m_desiredVelocity;
	float m_seekForce;
	float m_maxSpeed;
};

