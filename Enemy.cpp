#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Bullet.h"
#include "Player.h"
#include "Character.h"
#include "GameException.h"
using namespace std;
using namespace sf;

Texture Enemy::_Texture("E:\\ProiectPOO\\ProiectPOO\\zombiesprites.png");
Enemy::Enemy(float x, float y) :Character(x, y, 25, 1.0f, 0.0f), CurrentFrame(_Texture)
{

    
	
	
    for (int i = 0;i < 8;i++)
    {
		frames[i] = sf::IntRect({320*i,0},{ 320,320 });
    }
    CurrentFrame.setTextureRect(frames[0]);
	CurrentFrame.setScale(Vector2f(0.5f, 0.5f));
	CurrentFrame.setOrigin(Vector2f(160.f, 160.f));
   

    health = 20;
    speed = 1.3f;
    angle = 0.0f;
	CurrentFrame.setPosition(Position);

	collider.setSize(Vector2f(40.f, 40.f));
	collider.setFillColor(Color::Transparent);
	collider.setOrigin(collider.getSize() / 2.f);
	collider.setPosition(Position);

}
void Enemy::Draw(RenderWindow& window)
{
	window.draw(CurrentFrame);
	window.draw(collider);
}
void Enemy::TakeDamage(float value)
{
    health -= value;
	CurrentFrame.setColor(Color::Red);

    takesDamage = true;
    damageClock.restart();

    if (health < 0)
    {
        health = 0;
    }
    if (health == 0)
    {
        Die();
    }
}
void Enemy::Die()
{
	CurrentFrame.setColor(Color::Transparent);
    isDead = true;
}

void Enemy::Update(Player &player)
{
    
    if (!isDead && takesDamage && damageClock.getElapsedTime().asSeconds() >= 0.5f)
    {
		CurrentFrame.setColor(Color::White);
        takesDamage = false;
    }
    if (CollidesWPlayer(player)) {
        CurrentFrame.setTextureRect(frames[0]);
        if (player.getCanTakeDamage() && attackCooldown.getElapsedTime().asSeconds() >= 1.5f) {
			
            player.TakeDamage(10);
            attackCooldown.restart();
            player.setCanTakeDamage(false);
        }
    }
    else {
        Move(player);
        player.setCanTakeDamage(true);
    }
    
}
void Enemy::goBack()
{

}
void Enemy::Move(Player& player)
{
    if (AnimationClock.getElapsedTime().asSeconds() >= 0.1f)
    {
        frameIndex++;
        if (frameIndex >= 8) frameIndex = 0;
        CurrentFrame.setTexture(_Texture);
        CurrentFrame.setTextureRect(frames[frameIndex]);
        AnimationClock.restart();
    }
    Vector2f direction = player.getPlayerPosition() -   CurrentFrame.getPosition();
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0)
    {
        direction /= length;
    }
    angle = atan2(direction.y, direction.x)*180/3.14159265;
    CurrentFrame.setRotation(degrees(angle-90.f));
 
    float radians = angle * 3.14159265 / 180.f;

    Position += direction * speed;
	CurrentFrame.setPosition(Position);
	collider.setPosition(Position);
}
bool Enemy::GetState()
{
    return isDead;
}
bool Enemy::Collides(Bullet& bullet) {
    float distance = sqrt(pow(bullet.GetPosition().x - collider.getPosition().x, 2) +
        pow(bullet.GetPosition().y - collider.getPosition().y, 2));
    return distance < (bullet.GetRadius() + collider.getSize().x / 2.0f);
}
bool Enemy::CollidesWPlayer(Player& player)
{
    float distance = sqrt(pow(player.getPlayerPosition().x - collider.getPosition().x, 2) +
        pow(player.getPlayerPosition().y - collider.getPosition().y, 2));
    return distance < (player.getCircleRadius() + collider.getSize().x / 2.0f);
}