#pragma once
class EnemySpawner
{
public:

	static EnemySpawner &EnemySpawner::GetInstance();

	void RandomSpawner();
};

