#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;
Bullet::Bullet() :currVelocity(0.f, 0.f), speed(10), damage(10), isActive(true), angle(0)
{
	bullet.setRadius(5.f);
	bullet.setFillColor(Color::Yellow);
	bullet.setOrigin(Vector2f(5.f, 5.f));
	bullet.setPosition(Vector2f(0.f, 0.f));
}
void Bullet::set_position(float x, float y, float rotation)
{
    bullet.setPosition(Vector2f(x, y)); 

    float rotationInRadians = (rotation + 90) * (3.14159265359f / 180.f);


   
    currVelocity.x = cos(rotationInRadians) * speed;
    currVelocity.y = sin(rotationInRadians) * speed;
}

void Bullet::Update()
{
	if (isActive) bullet.move(currVelocity);
	if (bullet.getPosition().x < 0 || bullet.getPosition().x > 1366 || bullet.getPosition().y < 0 || bullet.getPosition().y > 768) {

		Destroy();
	}
}
void Bullet::draw(RenderWindow& window)
{
	window.draw(bullet);
}
void Bullet::Destroy()
{
	
	isActive = false;
}
bool Bullet::get_state()
{
	return isActive;
}


void Bullet::setAngle(float angle) {
	angle = angle;
}

void Bullet::activate() {
	isActive = true;
}

void Bullet::deactivate() {
	isActive = false;
}


Vector2f Bullet::GetPosition()
{
	return Vector2f(bullet.getPosition());
}