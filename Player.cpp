#include "Player.h"
#include "GameException.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Bullet.h"
using namespace std;
using namespace sf;
Texture Player::_texture("E:\\ProiectPOO\\ProiectPOO\\playersprites.png");
Player::Player(string _name, float _health, float _maxhealth, bool _isAlive, float x, float y, float _speed) : Character(x, y, _health, _speed, 0), CurrentFrame(_texture)
{
  
    
    for (int i = 0;i < 8;i++)
    {
        frames[i] = sf::IntRect({ 320 * i,0 }, { 320,320 });
    }
    CurrentFrame.setTextureRect(frames[0]);
    CurrentFrame.setScale(Vector2f(0.5f, 0.5f));
    CurrentFrame.setOrigin(Vector2f(160.f, 160.f));

	
    initialPosition = Position;
    health = _health;
	maxhealth = _maxhealth;
	isAlive = _isAlive;
    isDead = false;
    takesDamage = false;
	name = _name;
	
	radius = 20.f;
    
	CurrentFrame.setPosition(Position);
	collider.setSize(Vector2f(40.f, 40.f));
	collider.setFillColor(Color::Transparent);
	collider.setOrigin(collider.getSize() / 2.f);
	collider.setPosition(Position);
	angle = 0;
	if (_name == "nd")
	{
		GameException exception("Player", "Player name must be set");
		exception.Print();
	}
	if (_speed <= 0)
	{
		GameException exception("Player", "Player speed must be greater than 0");
		exception.Print();
	}
	canTakeDamage = true;
    /*
    if (!texture.getSize().x|| !texture.getSize().y)
    {
        GameException exception("Player", "Texture failed to load");
    }*/
}
void Player::setHighScore(int value)
{
	highScore = value;
}
void Player::Update()
{
    
    if (isAlive && takesDamage && damageClock.getElapsedTime().asSeconds() >= 0.5f)
    {
        CurrentFrame.setColor(Color::White);
        
        takesDamage = false;
    }
}
void Player::setShootingCooldown(float value)
{
	shootingCooldown = value;
}
void Player::setImmunity(bool value)
{
	isImune = value;
}
void Player::handleInput(RenderWindow& window)
{
    static int counter = 1; // Static counter to keep track of the message number

    if (isAlive) {
        Vector2f moveOffset(Vector2f(0.f, 0.f));
        bool isMoving = false;

        if (Keyboard::isKeyPressed(Keyboard::Key::W))
        {
            moveOffset.y -= speed;
            isMoving = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::S))
        {
            moveOffset.y += speed;
            isMoving = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::A))
        {
            moveOffset.x -= speed;
            isMoving = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::D))
        {
            moveOffset.x += speed;
            isMoving = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Left))
        {
            CurrentFrame.rotate(-degrees(speed));
            angle -= speed;
            isMoving = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Right))
        {
            CurrentFrame.rotate(degrees(speed));
            angle += speed;
            isMoving = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Space) && shootClock.getElapsedTime().asSeconds() > shootingCooldown)
        {
            shoot();
            shootClock.restart();
        }

        if (isMoving)
        {
            cout << "Player ul se deplaseaza " << counter << endl;
            counter++;
            if (counter > 6)
            {
                counter = 1;
            }
            if (AnimationClock.getElapsedTime().asSeconds() >= 0.1f)
            {
                frameIndex++;
                if (frameIndex >= 8) frameIndex = 0;
                CurrentFrame.setTexture(_texture);
                CurrentFrame.setTextureRect(frames[frameIndex]);
                AnimationClock.restart();
            }
            if (moveOffset != Vector2f(0.f, 0.f))
            {
                lastMovement = moveOffset;
                Position += moveOffset;
            }
        }
        else {
			CurrentFrame.setTextureRect(frames[0]);
        }
    }
    /*
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
    }*/
    if (Keyboard::isKeyPressed(Keyboard::Key::R))
    {
        Respawn();
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::L))
    {
        IncreaseScore(25);
    }
}
void Player::Heal(float value)
{
	if (health < maxhealth)
	{
		health += value;
		if (health > maxhealth) health = maxhealth;
		cout << "Player healed!" << endl;
	}
	if (health + value > maxhealth)
	{
        health = maxhealth;
	}
}
int Player::getScoreCount()
{
    return scoreCount;
}
void Player::ResetScoreCount()
{
    scoreCount = 0;
}
void Player::IncreaseScore(int value)
{
    score += value;
	scoreCount += value;
    if (score > highScore) highScore = score;
    cout << "Score increased!" << endl;
}
void Player::Respawn()
{
    health = maxhealth;
    isAlive = true;
    Position = Vector2f(initialPosition);
   
    collider.setPosition(Position);
	CurrentFrame.setPosition(Position);
    CurrentFrame.setColor(Color::White);
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
int Player::getScore()
{
    return score;
}
int Player::getHighScore()
{
	return highScore;
}
void Player::shoot()
{
    
        Bullet newBullet;
        float rotationinrads=angle* (3.14159265359f / 180.f);
        newBullet.set_position(Position.x, Position.y, angle);
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
		CurrentFrame.setPosition(Position);
        collider.setPosition(Position);
    }
}

void Player::draw(RenderWindow& window)
{
   // window.draw(sprite);
    

    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].draw(window);
    }
    window.draw(CurrentFrame);

    window.draw(collider);

}
void Player::TakeDamage(float value)
{
    cout << "Player takes damage!" << endl;
    if (canTakeDamage&&!isImune) {
        health -= value;
        canTakeDamage = false;
        damageCooldownClock.restart();
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
    
}
void Player::Die()
{
    CurrentFrame.setColor(Color::Transparent);
    isAlive = false;
    cout << "Player is dead!" << endl;
    cout << "Your score:" << score << "     Your high score:" << highScore << endl;
}
void Player::goBack()
{
    Position -= lastMovement;
}
Vector2f Player::getPlayerPosition()
{
    return Position;
}
float Player::get_angle()
{
	return angle;
}
void Player::setPlayerPosition(float x, float y)
{
    Position = Vector2f(x, y);
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
    sprintf_s(buff, "Player %s %.2f/%.2f is at position: %.2f, %.2f", name.c_str(), health, maxhealth, Position.x, Position.y);
    return buff;
}
bool Player::get_state()
{
	return isAlive;
}
float Player::getCircleRadius()
{
    return radius;
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
