#include "Player.h"
#include "GameException.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Bullet.h"
using namespace std;
using namespace sf;

Player::Player(string _name, float _health, float _maxhealth, bool _isAlive, float x, float y, float _speed) : name(_name), speed(_speed), health(_health), maxhealth(_maxhealth), isAlive(_isAlive), position(Vector2f(x, y)), initialPosition(Vector2f(x, y)), lastMovement(Vector2f(x, y))
{


    //playerCircle
    playerCircle.setRadius(20.f);
    playerCircle.setFillColor(Color(255, 220, 180));
    playerCircle.setOutlineColor(Color::Black);
    playerCircle.setOutlineThickness(2.f);
    playerCircle.setOrigin(Vector2f(20.f, 20.f));
    playerCircle.setPosition(position);
    
    
    bullets.push_back(b);
    //Gun
	gun.setSize(Vector2f(8.f, 16.f));
    gun.setFillColor(Color(128, 128, 128));
    gun.setOutlineColor(Color::Black);
	gun.setOutlineThickness(2.f);
    gun.setOrigin(Vector2f(4.f, -20.f));
    gun.setPosition(position);
	
    //collider
    collider.setSize(Vector2f(40.f, 40.f));
    collider.setFillColor(Color::Transparent);
    collider.setOrigin(collider.getSize() / 2.f); 
    collider.setPosition(position);
    rotation = 0;
	if (name == "nd")
	{
		GameException exception("Player", "Player name must be set");
		exception.Print();
	}
    if (speed <= 0)
    {
        GameException exception("Player", "Player speed must be greater than 0");
        exception.Print();
    }
    canTakeDamage = true;
}
void Player::Update()
{
    if (isAlive && takesDamage && damageClock.getElapsedTime().asSeconds() >= 0.5f)
    {
        playerCircle.setFillColor(sf::Color(255, 220, 180));
        gun.setFillColor(sf::Color(128, 128, 128));
        takesDamage = false;
    }
}
void Player::handleInput(RenderWindow& window)
{
    if (isAlive) {
        Vector2f moveOffset(Vector2f(0.f, 0.f));
        if (Keyboard::isKeyPressed(Keyboard::Key::W))
        {
            moveOffset.y -= speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::S))
        {
            moveOffset.y += speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::A))
        {
            moveOffset.x -= speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::D))
        {
            moveOffset.x += speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Left))
        {
            playerCircle.rotate(degrees(-speed));
            gun.rotate(degrees(-speed));
            rotation -= speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Right))
        {
            playerCircle.rotate(degrees(speed));
            gun.rotate(degrees(speed));
            rotation += speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Space)&& shootClock.getElapsedTime().asSeconds() > 1)
        {
            shoot();
            shootClock.restart();
			
        }
		if (moveOffset!=Vector2f(0.f,0.f))
		{
			lastMovement = moveOffset;
			position += moveOffset;

		}
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::P))
    {
        if (canTakeDamage) 
        {
            TakeDamage(10);
            canTakeDamage = false;
        }
    }
    else {
        canTakeDamage = true;
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::R))
    {
        Respawn();
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::L))
    {
        IncreaseScore(25);
    }
}
void Player::IncreaseScore(int value)
{
    score += value;
    if (score > highScore) highScore = score;
    cout << "Score increased!" << endl;
}
void Player::Respawn()
{
    health = maxhealth;
    isAlive = true;
    position = Vector2f(initialPosition);
    playerCircle.setPosition(position);
    gun.setPosition(position);
    collider.setPosition(position);
    playerCircle.setFillColor(Color(255, 220, 180));
    playerCircle.setOutlineColor(Color::Black);
    gun.setOutlineColor(Color::Black);
    gun.setFillColor(Color(128, 128, 128));
    score = 0;
    cout << "Player respawned" << endl;
}
float Player :: getHealth()
{
    return health;
}
float Player :: getMaxHealth()
{
    return maxhealth;
}
void Player::set_isShooting(bool value)
{
	isShooting = value;
}
bool Player::is_shooting()
{
	return isShooting;
}
void Player::shoot()
{
    
        Bullet newBullet;
        float rotationinrads=rotation* (3.14159265359f / 180.f);
        newBullet.set_position(position.x, position.y, rotation);
        bullets.push_back(newBullet);
    
}
void Player::move()
{
    for (size_t i = 0; i < bullets.size();) {
  
        if (!bullets[i].get_state()) {
            bullets.erase(bullets.begin() + i); 
        }
        else {
            bullets[i].Update();
            i++;
      
        }
    }

    if (isAlive) {
        playerCircle.setPosition(position);
        gun.setPosition(position);
        collider.setPosition(position);
    }
}

void Player::draw(RenderWindow& window)
{
   // window.draw(sprite);
    

    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].draw(window);
    }
    window.draw(playerCircle);
    window.draw(gun);
    window.draw(collider);

}
void Player::TakeDamage(float value)
{
    cout << "Player takes damage!" << endl;
    if (canTakeDamage) {
        health -= value;
        canTakeDamage = false;
        damageCooldownClock.restart();
        playerCircle.setFillColor(Color::Red);
        gun.setFillColor(Color(139, 0, 0));

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
    
}
void Player::Die()
{
    playerCircle.setFillColor(Color::Transparent);
    gun.setFillColor(Color::Transparent);
    playerCircle.setOutlineColor(Color::Transparent);
    gun.setOutlineColor(Color::Transparent);
    isAlive = false;
    cout << "Player is dead!" << endl;
    cout << "Your score:" << score << "     Your high score:" << highScore << endl;
}
void Player::goBack()
{
	position -= lastMovement;
}
Vector2f Player::getPlayerPosition()
{
    return position;
}
float Player::get_angle()
{
	return rotation;
}
void Player::setPlayerPosition(float x, float y)
{
    position = Vector2f(x, y);
    move();
}
bool Player::getCanTakeDamage()
{
    return canTakeDamage;
}
void Player::setCanTakeDamage(bool value)
{
    canTakeDamage = value;
}
string Player::get_name()
{
    return name;
}

void Player::set_name(string _name)
{
    name = _name;
}
RectangleShape Player::getPlayerCollider()
{
	return collider;
}
char* Player::toStr()
{
    sprintf_s(buff, "Player %s %.2f/%.2f is at position: %.2f, %.2f", name.c_str(), health, maxhealth, position.x, position.y);
    return buff;
}
bool Player::get_state()
{
	return isAlive;
}
float Player::getCircleRadius()
{
    return playerCircle.getRadius();
}
Player& Player::operator=(Player& player)
{
    name = player.name;
    speed = player.speed;
    health = player.health;
    maxhealth = player.maxhealth;
    isAlive = player.isAlive;
    
    return *this;

}
std::vector<Bullet>& Player::getBullets() {
    return bullets;
}
ostream& operator<<(ostream& out, Player& player)
{
    out << player.toStr();
    return out;
}
