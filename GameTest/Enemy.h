#pragma once
class Enemy
{
public:
	static Enemy& Enemy::GetInstance();

	void CreateEnemySprite(int bitMapCol, int frame, float speed, float plX, float plY);
	void Update(float deltaTime);
	void EnemyMovement(float plX, float plY);
	void Render();
	void EnemyDestructor();

	int frame = 0;
};

