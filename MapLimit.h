#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Player.h"
using namespace std;
using namespace sf;
class MapLimit
{
private:
	RectangleShape limit;
public:
	MapLimit(float x=0, float y=0, float width=0, float height=0);
	void draw(RenderWindow& window);
	bool checkCollision(Player& player);
	MapLimit& operator=(MapLimit& _limit);
	//bool checkCollisionBullet(Bullet& bullet);
	
};

