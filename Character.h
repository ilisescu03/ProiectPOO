#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class Character
{
protected:

	float health;
	float speed;
	float angle;
	bool isAlive;
	bool takesDamage;
	bool isDead;
	bool canTakeDamage;
	Clock damageClock;
	Vector2f Position;
public:
	Character(float x=0.f, float y=0.f, float _health=0.f, float _speed=0.f, float _angle=0.f);
	virtual void Update();
	virtual void TakeDamage(float value);
	virtual void Die();
};

