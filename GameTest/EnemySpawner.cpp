#include "stdafx.h"
#include "stdlib.h"
#include <math.h>

#include "EnemySpawner.h"
#include "app\main.h"
#include "app\app.h"

CSimpleSprite *enemySprite;

float initialPosX = (float) (WINDOW_WIDTH); //1050.0f;
float initialPosY = (float) (WINDOW_HEIGHT / 2); //300.0f;

float scale = 0.5f;
float angle = 1.6f;
float speed = 5.0f;
int spawnInterval;


EnemySpawner &EnemySpawner::GetInstance()
{
	static EnemySpawner theEnemySpawnerClass;
	return 	theEnemySpawnerClass;
}

void EnemySpawner::RandomSpawner()
{
	//GetConsoleWindowInfo();

	CSimpleSprite* newEnemySprite;

	float randPosY = (float) (rand() % 730 + 15);

	newEnemySprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 15);

	newEnemySprite->SetPosition(initialPosX + newEnemySprite->GetHeight(), randPosY); //(1000.0f, 750.0f) right top  (1000.0f, 10.0f) right bottom 
	newEnemySprite->SetFrame(0);
	newEnemySprite->SetScale(scale);
	newEnemySprite->SetAngle(angle);

	enemySprite = newEnemySprite;
	//return enemySprite;
}

void EnemySpawner::Update(float deltaTime)
{
	enemySprite->Update(deltaTime);
}

void EnemySpawner::EnemyMovement()
{
	float x, y;
	enemySprite->GetPosition(x, y);
	//if (x < 0.0f)
	//{
	//	EnemyDestructor();
	//}
	x -= speed;
	enemySprite->SetPosition(x, y);
}

void EnemySpawner::Render()
{
	enemySprite->Draw();
}

void EnemySpawner::EnemyDestructor()
{
	delete enemySprite;
}
