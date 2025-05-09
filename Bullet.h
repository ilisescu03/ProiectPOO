#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class Bullet
{
private:
	Sprite bulletSprite;
	Clock bulletClock;
	CircleShape bulletCollider;
	static Texture _texture;
	Vector2f currVelocity;
	float angle;
	int damage;
	int speed;
	bool isActive;
public:
	Bullet();
	void set_position(float x, float y, float rotation);
	void setAngle(float angle);
	void activate();
	void deactivate();
	void Update();
	void draw(RenderWindow& window);
	void Destroy();
	bool get_state();
	float GetRadius();
	Vector2f GetPosition();

};

