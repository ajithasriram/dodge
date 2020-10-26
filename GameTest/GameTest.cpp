//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
#include <thread>
#include <functional>
#include <chrono>
//------------------------------------------------------------------------
#include "app\app.h"
#include "app\main.h"
#include "EnemySpawner.h"
#include "Player.h"
#include "Enemy.h"
#include "ScoreController.h"
//------------------------------------------------------------------------

Player* playerObject;
Enemy* enemyObject1;
ScoreController scorer;
float x, y;

void Init()
{
	playerObject->CreatePlayerSprite();
	float x, y;
	playerObject->GetPosition(x, y);
	enemyObject1->CreateEnemySprite(15, 0, 25.0f, x, y);
}

void Update(float deltaTime)
{
	if (life > 0)
	{
		playerObject->Update(deltaTime);
		enemyObject1->Update(deltaTime);

		//enemy movement
		float x, y;
		playerObject->GetPosition(x, y);
		enemyObject1->EnemyMovement(x, y);

		if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
		{
			App::PlaySound(".\\TestData\\Test.wav");
		}
	}
}

void Render()
{
	char textBuffer[64];
	App::DrawLine(0.0f, 50.0f, (float)WINDOW_WIDTH, 50.0f);

	if (life > 0)
	{
		playerObject->Render();
		enemyObject1->Render();
	}

	if (life == 0)
	{
		playerObject->PlayerDestructor();
		enemyObject1->EnemyDestructor();

		sprintf(textBuffer, "High Score: %d", score);
		App::Print((float)WINDOW_WIDTH / 2.3f, (float)WINDOW_HEIGHT / 2.0f, "GAME OVER");
		App::Print((float)WINDOW_WIDTH / 2.3f, (float)WINDOW_HEIGHT / 3.0f, textBuffer);
	}

	sprintf(textBuffer, "Life: %d", life);
	App::Print(200, 25, textBuffer);

	sprintf(textBuffer, "Score: %d", score);
	App::Print(500, 25, textBuffer);
}

void Shutdown()
{
	playerObject->PlayerDestructor();
	enemyObject1->EnemyDestructor();
}