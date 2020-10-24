//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Eample data....
//------------------------------------------------------------------------
CSimpleSprite *playerSprite;
CSimpleSprite *enemySprite;

enum
{
	ANIM_FORWARDS,
	ANIM_BACKWARDS,
	ANIM_LEFT,
	ANIM_RIGHT,
};
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	//------------------------------------------------------------------------
	// Example Sprite Code....
	

	//testSprite = App::CreateSprite(".\\TestData\\Test.bmp", 8, 4);
	//testSprite->SetPosition(400.0f, 400.0f);
	//float speed = 1.0f / 15.0f;
	//testSprite->CreateAnimation(ANIM_BACKWARDS, speed, { 0,1,2,3,4,5,6,7 });
	//testSprite->CreateAnimation(ANIM_LEFT, speed, { 8,9,10,11,12,13,14,15 });
	//testSprite->CreateAnimation(ANIM_RIGHT, speed, { 16,17,18,19,20,21,22,23 });
	//testSprite->CreateAnimation(ANIM_FORWARDS, speed, { 24,25,26,27,28,29,30,31 });
	//testSprite->SetScale(2.0f);

	playerSprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 12);
	playerSprite->SetPosition(200.0f, 200.0f);
	playerSprite->SetFrame(2);
	playerSprite->SetScale(1.0f);
	playerSprite->SetAngle(4.7f);

	enemySprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 15);
	enemySprite->SetPosition(1050.0f, 300.0f);	//outside right frame
	enemySprite->SetFrame(2);
	enemySprite->SetScale(0.5f);
	enemySprite->SetColor(1.0f, 0.5f, 0.0f);
	enemySprite->SetAngle(1.6f);
	//------------------------------------------------------------------------
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	playerSprite->Update(deltaTime);
	//enemySprite->Update(deltaTime);
	
	//gravity
	float x, y;
	playerSprite->GetPosition(x, y);
	y -= 1.0f;
	playerSprite->SetPosition(x, y);

	//enemy plane movement
	enemySprite->GetPosition(x, y);
	x -= 2.0f;
	enemySprite->SetPosition(x, y);

	//if (App::GetController().GetLeftThumbStickX() > 0.5f)
	//{
	//	playerSprite->SetAnimation(ANIM_RIGHT);
	//	float x, y;
	//	playerSprite->GetPosition(x, y);
	//	x += 1.0f;
	//	playerSprite->SetPosition(x, y);
	//}
	//if (App::GetController().GetLeftThumbStickX() < -0.5f)
	//{
	//	playerSprite->SetAnimation(ANIM_LEFT);
	//	float x, y;
	//	playerSprite->GetPosition(x, y);
	//	x -= 1.0f;
	//	playerSprite->SetPosition(x, y);
	//}
	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		playerSprite->SetAnimation(ANIM_FORWARDS);
		float x, y;
		playerSprite->GetPosition(x, y);
		y += 3.0f;
		playerSprite->SetPosition(x, y);
	}
	//if (App::GetController().GetLeftThumbStickY() < -0.5f)
	//{
	//	playerSprite->SetAnimation(ANIM_BACKWARDS);
	//	float x, y;
	//	playerSprite->GetPosition(x, y);
	//	y -= 1.0f;
	//	playerSprite->SetPosition(x, y);
	//}
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, false))
	//{
	//	playerSprite->SetScale(playerSprite->GetScale() + 0.1f);
	//}
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, false))
	//{
	//	playerSprite->SetScale(playerSprite->GetScale() - 0.1f);
	//}
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false))
	//{
	//	playerSprite->SetAngle(playerSprite->GetAngle() + 0.1f);
	//}
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false))
	//{
	//	playerSprite->SetAngle(playerSprite->GetAngle() - 0.1f);
	//}
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	//{
	//	playerSprite->SetAnimation(-1);
	//}
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
	//{
	//	playerSprite->SetVertex(0, playerSprite->GetVertex(0) + 5.0f);
	//}
	//------------------------------------------------------------------------
	// Sample Sound.
	//------------------------------------------------------------------------
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
	{
		App::PlaySound(".\\TestData\\Test.wav");
	}
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	

	//------------------------------------------------------------------------
	// Example Line Drawing.
	//------------------------------------------------------------------------
	//static float a = 0.0f;
	//float r = 1.0f;
	//float g = 1.0f;
	//float b = 1.0f;
	//a += 0.1f;
	//for (int i = 0; i < 20; i++)
	//{

	//	float sx = 200 + sinf(a + i * 0.1f)*60.0f;
	//	float sy = 200 + cosf(a + i * 0.1f)*60.0f;
	//	float ex = 700 - sinf(a + i * 0.1f)*60.0f;
	//	float ey = 700 - cosf(a + i * 0.1f)*60.0f;
	//	g = (float)i / 20.0f;
	//	b = (float)i / 20.0f;
	//	App::DrawLine(sx, sy, ex, ey,r,g,b);
	//}

	//------------------------------------------------------------------------
	// Example Sprite Code....
	playerSprite->Draw();
	enemySprite->Draw();
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// Example Text.
	//------------------------------------------------------------------------
	App::Print(100, 100, "Sample Text");

}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	//------------------------------------------------------------------------
	// Example Sprite Code....
	delete playerSprite;
	delete enemySprite;
	//------------------------------------------------------------------------
}