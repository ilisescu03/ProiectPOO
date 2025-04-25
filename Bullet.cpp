#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;
Texture Bullet::_texture("E:\\ProiectPOO\\ProiectPOO\\bullet.png");
Bullet::Bullet() :currVelocity(0.f, 0.f), speed(10), damage(10), isActive(true), angle(0), bulletSprite(_texture)
{
	bulletSprite.setTexture(_texture);
	Vector2u texSize = _texture.getSize(); // dimensiunea în pixeli a texturii
	bulletSprite.setScale(Vector2f(0.06f, 0.06f));
	bulletSprite.setOrigin(Vector2f(texSize.x / 2.f, texSize.y / 2.f));

	bulletCollider.setRadius(4.f);
	bulletCollider.setFillColor(Color::Transparent);
	bulletCollider.setOrigin(Vector2f(5.f, 5.f));
	bulletCollider.setPosition(Vector2f(0.f, 0.f));
}
void Bullet::set_position(float x, float y, float rotation)
{
	bulletSprite.setPosition(Vector2f(x, y));
	bulletCollider.setPosition(Vector2f(x, y));
	bulletSprite.setRotation(degrees(rotation));
    float rotationInRadians = (rotation + 90) * (3.14159265359f / 180.f);


   
    currVelocity.x = cos(rotationInRadians) * speed;
    currVelocity.y = sin(rotationInRadians) * speed;
}

void Bullet::Update()
{
	if (isActive){ bulletCollider.move(currVelocity);
	bulletSprite.move(currVelocity);
	}
	if (bulletCollider.getPosition().x < 0 || bulletCollider.getPosition().x > 1366 || bulletCollider.getPosition().y < 0 || bulletCollider.getPosition().y > 768) {

		Destroy();
	}
}
void Bullet::draw(RenderWindow& window)
{
	window.draw(bulletSprite);
	window.draw(bulletCollider);
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
	return Vector2f(bulletCollider.getPosition());
}
float Bullet::GetRadius()
{
	return bulletCollider.getRadius();
}