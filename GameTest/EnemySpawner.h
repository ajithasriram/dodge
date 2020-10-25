#pragma once
class EnemySpawner
{
public:

	static EnemySpawner &EnemySpawner::GetInstance();

	void GetConsoleWindowInfo();

	void RandomSpawner();
	void Update(float deltaTime);
	void EnemyMovement();
	void Render();
	void EnemyDestructor();
};

