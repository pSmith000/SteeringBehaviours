#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "SeekComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "FleeEnemy.h"
#include "SeekEnemy.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50, 50 });

	FleeEnemy* enemy = new FleeEnemy(player, 100, 100, "Enemy");
	SeekEnemy* enemy2 = new SeekEnemy(player, 100, 100, "Enemy");
	enemy->getTransform()->setScale({ 50, 50 });
	enemy2->getTransform()->setScale({ 50, 50 });

	

	addActor(player);
	//addActor(enemy);
	addActor(enemy2);
}
