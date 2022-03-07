#pragma once
#include "Actor.h"
#include "ActorArray.h"
#include <Vector2.h>

class SteeringComponent;
class MoveComponent;

class Agent :
	public Actor
{
public:
	void start() override;
	void update(float deltaTime) override;
	void onAddComponent(Component* component) override;
	float getMaxForce();
	void setMaxForce(float maxForce);
	MoveComponent* getMoveComponent();

private:
	DynamicArray<SteeringComponent*> m_steeringComponents;
	float m_maxForce;
	MoveComponent* m_moveComponent;
	MathLibrary::Vector2 m_force;
};

