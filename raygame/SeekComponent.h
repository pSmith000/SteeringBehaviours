#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>
class SeekComponent :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce();
	//SeekComponent(Actor* target, const char* name = "Seek Component");
	SeekComponent(MathLibrary::Vector2 position, const char* name = "Seek Component");

	Actor* getTarget() { return m_actorTarget; }

	void setPosition(MathLibrary::Vector2 target) { m_target = target; }

	void setSpeed(float speed) { m_maxSpeed = speed; }

	void update(float deltaTime) override;

private:
	Actor* m_actorTarget;
	MathLibrary::Vector2 m_target;
	MathLibrary::Vector2 m_currentVelocity;
	MathLibrary::Vector2 m_steeringForce;
	MathLibrary::Vector2 m_desiredVelocity;
	float m_seekForce;
	float m_maxSpeed;
	bool hasActor;
};

