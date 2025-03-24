#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "MapLimit.h"
#include "Bullet.h"
#include "GameException.h"
#include "HealthBar.h"
#include "Enemy.h"
using namespace std;
using namespace sf;
class GameRun
{
	RenderWindow * window;
	Player * player;
	HealthBar * healthbar;
	MapLimit *limits[4];
	Enemy * enemy;
	vector<Enemy*> enemies;
public:
	GameRun();
	~GameRun();
	void Run();
};

