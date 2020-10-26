#include "stdafx.h"
#include <math.h>

#include "Enemy.h"
#include "Player.h"
#include "App/main.h"
#include "App/app.h"
#include "ScoreController.h"

CSimpleSprite* enemySprite;

float initialPosX = (float)(WINDOW_WIDTH);
float initialPosY = (float)(WINDOW_HEIGHT / 2);

float scale = 0.5f;
float angle = 1.6f;
float speed = 5.0f;
int spawnInterval;

bool isCollision = false;

Enemy& Enemy::GetInstance()
{
	static Enemy theEnemyClass;
	return 	theEnemyClass;
}

void Enemy::CreateEnemySprite(int bitMapCol, int frame, float sp, float plX, float plY)
{	
	enemySprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, bitMapCol);
	enemySprite->SetPosition(initialPosX, plY);
	enemySprite->SetFrame(frame);
	enemySprite->SetAngle(angle);
	enemySprite->SetScale(scale);
	speed = sp;
}



void Enemy::Update(float deltaTime)
{
	enemySprite->Update(deltaTime);
}

void Enemy::EnemyMovement(float plX, float plY)
{
	float x, y;
	enemySprite->GetPosition(x, y);

	//collision check
	if (life > 0 &&  (abs(x - plX) < 10 && abs(y - plY) < 10))
	{
		life -= 1;
		isCollision = true;
	}

	if ( life > 0 && (isCollision == true || x < (0.0f - (enemySprite->GetWidth() / 8.0f))))
	{
		score += 10;
		y = plY;
		x = initialPosX;
		enemySprite->SetPosition(x, y);
		isCollision = false;
	}
	x -= speed;
	enemySprite->SetPosition(x, y);
}

void Enemy::Render()
{
	enemySprite->Draw();
}

void Enemy::EnemyDestructor()
{
	delete enemySprite;
}