#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Bullet.h"
#include "Player.h"
using namespace std;
using namespace sf;
class Enemy
{
private:
	CircleShape EnemyCircle;
	RectangleShape LeftHand;
	RectangleShape RightHand;
	Clock damageClock;
	Clock attackCooldown;
	Vector2f Position;
	bool takesDamage=false;
	bool isDead = false;
	float health;
	float speed;
	float angle;
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

