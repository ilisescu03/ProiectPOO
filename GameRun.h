#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "MapLimit.h"
#include "Bullet.h"
#include "GameException.h"
using namespace std;
using namespace sf;
class GameRun
{
	RenderWindow * window;
	Player * player;
	MapLimit *limits[4];

public:
	GameRun();
	~GameRun();
	void Run();
};

