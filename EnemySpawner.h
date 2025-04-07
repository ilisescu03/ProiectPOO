#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Enemy.h"
#include "Player.h"
using namespace std;
using namespace sf;
class EnemySpawner
{
	
	vector<Enemy> enemies;
	Clock SpawnClock;
	float spawnTime;
public:
	EnemySpawner();
	void Update(Player &player, RenderWindow &window);
	void ResetTime();
	void DecreaseTime();
	void ClearVector();
	float getRandomX();
	float getRandomY();
};

