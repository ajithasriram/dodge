#pragma once
class Player
{
public:
	static Player& Player::GetInstance();

	void CreatePlayerSprite();
	void Update(float deltaTime);
	void Render();
	void PlayerDestructor();
};