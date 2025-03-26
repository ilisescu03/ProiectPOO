#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Bullet.h"
#include "Player.h"
#include "Character.h"
using namespace std;
using namespace sf;
class Enemy : public Character
{
private:
	CircleShape EnemyCircle;
	RectangleShape LeftHand;
	RectangleShape RightHand;
	Clock damageClock;
	Clock attackCooldown;

	
public:
	Enemy(float x = 0.f, float y = 0.f);
	bool Collides(Bullet & bullet);
	bool CollidesWPlayer(Player &player);
	bool GetState();
	void goBack();
	void Update(Player &player);
	void Move(Player &player);
	void Draw(RenderWindow &window);
	void TakeDamage(float value);
	void Die();
};

