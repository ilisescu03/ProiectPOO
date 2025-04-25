#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Collectible.h"
#include "Player.h"
using namespace std;
using namespace sf;
class CollectibleSpawner
{
	vector<Collectible> Collectibles;
	Clock SpawnClock;
	Clock armorClock;
	Clock fireRateClock;
	bool armorActive = false;
	bool fireRateActive = false;
	float maxspawnTime;
	float minspawnTime;
public:
	CollectibleSpawner();
	void Update(RenderWindow& window, Player &player);
	void ResetTime();
	void DecreaseTime();
	void ClearVector();
	float getRandomX();
	string getRandomType();
	float getRandomY();
	float getRandomTime();
	Collectible getCollectible(int index);
	int getCollectibleCount();
	//bool checkCollision(Collectible& collectible, Player& player);
};

