#pragma once
#include "Component.h"
#include <Vector2.h>

class MoveComponent :
	public Component
{
public:
	MoveComponent(const char* name = "MoveComponent") : Component::Component(name) {}

	/// <summary>
	/// Gets the current speed and direction of this actor
	/// </summary>
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	/// <summary>
	/// Set the current speed and direction of this actor
	/// </summary>
	/// <param name="velocity">The new velovity of this actor</param>
	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }

	/// <summary>
	/// Get the maximum magnitude of this actors velocity vector
	/// </summary>
	float getMaxSpeed() { return m_maxSpeed; }

	void setUpdateFacing(bool value) { m_updateFacing = value; }
	bool getUpdateFacing() { return m_updateFacing; }

	/// <summary>
	/// Set the magnitude of this actors velocity vector
	/// </summary>
	/// <param name="maxSpeed"></param>
	void setMaxSpeed(float maxSpeed) { m_maxSpeed = maxSpeed; }

	/// <summary>
	/// Inherited from component class
	/// </summary>
	/// <param name="deltaTime"></param>
	void update(float deltaTime) override;

private:
	MathLibrary::Vector2 m_velocity;
	float m_maxSpeed;
	bool m_updateFacing;
};

