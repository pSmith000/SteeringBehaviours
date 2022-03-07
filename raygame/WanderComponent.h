#pragma once
#include "Component.h"
#include <Vector2.h>
class WanderComponent :
	public Component
{
public:
	WanderComponent() {};
	WanderComponent(float distance, float radius, const char* name = "Wander Component");

	void setDistance(float distance) { m_distance = distance; }
	void setRadius(float radius) { m_radius = radius; }

	void update(float deltaTime) override;

private:
	float m_distance;
	float m_radius;
	float m_force;
	MathLibrary::Vector2 m_angle;
};

