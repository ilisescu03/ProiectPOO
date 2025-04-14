#include "Character.h"
Character::Character(float x, float y, float _health, float _speed, float _angle)
{
	
	Position = Vector2f(x, y);
	health = _health;
	speed = _speed;
	angle = _angle;
	isAlive = true;
	takesDamage = false;
	isDead = false;
	canTakeDamage = true;
}
void Character::Update()
{
	cout << "Polymorphism not working!!" << endl;
}
void Character::TakeDamage(float value)
{
	cout << "Polymorphism not working!!" << endl;
}
void Character::Die()
{
	cout << "Polymorphism not working!!" << endl;
}