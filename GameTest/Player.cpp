#include "stdafx.h"

#include "Player.h"
#include "app/app.h"
#include "app/main.h"

float playerInitialPosX = (float)(WINDOW_WIDTH / 5.0f);
float playerInitialPosY = (float)(WINDOW_HEIGHT / 2);

float playerScale = 1.0f;
float playerAngle = 4.7f;
float playerVerticalSpeed = 7.0f;

enum
{
	ANIM_FORWARDS,
	ANIM_BACKWARDS,
	ANIM_LEFT,
	ANIM_RIGHT,
};

CSimpleSprite* playerSprite;

Player& Player::GetInstance()
{
	static Player thePlayerClass;
	return 	thePlayerClass;
}

void Player::CreatePlayerSprite()
{
	playerSprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 12);

	playerSprite->SetPosition(playerInitialPosX, playerInitialPosY);
	playerSprite->SetFrame(2);
	playerSprite->SetScale(playerScale);
	playerSprite->SetAngle(playerAngle);
}

void Player::Update(float deltaTime)
{
	playerSprite->Update(deltaTime);

	float x, y;
	
	//Gravity
	playerSprite->GetPosition(x, y);
	if (y > (50.0f + (playerSprite->GetHeight() / 8.0f)))
	{
		y -= 3.0f;
		playerSprite->SetPosition(x, y);
	}

	//Player Movement Control
	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		playerSprite->SetAnimation(ANIM_FORWARDS);
		float playerPosX, playerPosY;
		playerSprite->GetPosition(playerPosX, playerPosY);
		if (playerPosY < (float)(WINDOW_HEIGHT - (playerSprite->GetHeight() / 8.0f)))
		{
			playerPosY += 7.0f;
			playerSprite->SetPosition(playerPosX, playerPosY);
		}
	}
}

void Player::GetPosition(float &x, float &y)
{
	playerSprite->GetPosition(x, y);
}

void Player::Render()
{
	playerSprite->Draw();
}

void Player::PlayerDestructor()
{
	delete playerSprite;
}