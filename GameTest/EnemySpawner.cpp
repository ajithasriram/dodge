#include "stdafx.h"
#include "stdlib.h"
#include "windows.h"
//#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
//#include <unistd.h> // for STDOUT_FILENO
#include "EnemySpawner.h"

#include <windows.h> 
#include <math.h>

#include "app\main.h"
#include "app\app.h"

CSimpleSprite *enemySprite;

//struct winsize size;
//ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

HANDLE hConsole;
CONSOLE_SCREEN_BUFFER_INFO consoleInfo = {};
SMALL_RECT srctWindow;

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

void EnemySpawner::GetConsoleWindowInfo()
{
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	srctWindow = consoleInfo.srWindow;
}

void EnemySpawner::RandomSpawner()
{
	//GetConsoleWindowInfo();

	//float randPosY = (float) (rand() % 730 + 15);

	enemySprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 15);

	enemySprite->SetPosition(initialPosX + enemySprite->GetHeight(), initialPosY); //(1000.0f, 750.0f) right top  (1000.0f, 10.0f) right bottom 
	enemySprite->SetFrame(0);
	enemySprite->SetScale(scale);
	enemySprite->SetAngle(angle);

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
