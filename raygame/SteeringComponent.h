#pragma once
#include "Component.h"
#include <Vector2.h>
class Actor;

class SteeringComponent :
	public Component
{
public:
	SteeringComponent() { m_target = nullptr; }
	SteeringComponent(Actor* actor) { m_target = actor; }
	virtual MathLibrary::Vector2 calculateForce() = 0;
	Actor* getTarget() { return m_target; }
	void setTarget(Actor* target) { m_target = target; }

private:
	Actor* m_target = nullptr;
};

