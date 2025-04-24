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
#include "Collectible.h"
#include "EnemySpawner.h"
#include "Background.h"
#include "Character.h"
#include "GameHUD.h"
using namespace std;
using namespace sf;
class GameRun
{
	Clock armorClock;
	Clock fireRateClock;
	bool armorActive = false;
	bool fireRateActive = false;
	GameHUD* gameHUD;
	Collectible* collectible;
	Collectible* collectible1;
	Collectible* collectible2;
	EnemySpawner * enemySpawner;
	RenderWindow * window;
	Player * player;
	MapLimit *limits[4];
	Background *background;
public:
	GameRun();
	~GameRun();
	void Run();
};

