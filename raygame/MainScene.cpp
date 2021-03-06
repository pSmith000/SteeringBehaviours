#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "StateMachineComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Agent.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50, 50 });


	Agent* agent = new Agent();
	agent->getTransform()->setScale({ 50,50 });
	agent->getTransform()->setWorldPostion({ 50, 50 });
	agent->setMaxForce(200);
	agent->addComponent(new SpriteComponent("Images/enemy.png"));

	WanderComponent* comp = new WanderComponent(1000, 200, 100);
	agent->addComponent(comp);

	SeekComponent* seekComponent = new SeekComponent();
	seekComponent->setSteeringForce(50);
	seekComponent->setTarget(player);
	agent->addComponent(seekComponent);
	agent->addComponent<StateMachineComponent>();

	addActor(player);
	addActor(agent);
}
