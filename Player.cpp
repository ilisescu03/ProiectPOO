#include "Player.h"
#include "GameException.h"
#include <iostream>
#include <string>

using namespace std;
Player::Player(string _name, float _health, float _maxhealth, bool _isAlive, float x, float y, float _speed) : name(_name), speed(_speed), health(_health), maxhealth(_maxhealth), isAlive(_isAlive), position(Vector2f(x, y)), initialPosition(Vector2f(x, y))
{
   
   
    //playerCircle
    playerCircle.setRadius(20.f);
    playerCircle.setFillColor(Color(255, 220, 180));
    playerCircle.setOutlineColor(Color::Black);
    playerCircle.setOutlineThickness(2.f);
    playerCircle.setOrigin(Vector2f(20.f, 20.f));
    playerCircle.setPosition(position);
    
    

    //Gun
	gun.setSize(Vector2f(8.f, 16.f));
    gun.setFillColor(Color(128, 128, 128));
    gun.setOutlineColor(Color::Black);
	gun.setOutlineThickness(2.f);
    gun.setOrigin(Vector2f(4.f, -20.f));
    gun.setPosition(position);
	
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
}

void Player::handleInput()
{
    if (isAlive) {
        if (Keyboard::isKeyPressed(Keyboard::Key::W))
        {
            position.y -= speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::S))
        {
            position.y += speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::A))
        {
            position.x -= speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::D))
        {
            position.x += speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Left))
        {
            playerCircle.rotate(degrees(-speed));
            gun.rotate(degrees(-speed));
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Right))
        {
            playerCircle.rotate(degrees(speed));
            gun.rotate(degrees(speed));
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::P))
    {
        TakeDamage(10);
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::R))
    {
		health = maxhealth;
        isAlive = true;
        position = Vector2f(initialPosition);
        playerCircle.setPosition(position);
        gun.setPosition(position);
        playerCircle.setFillColor(Color(255, 220, 180));
		playerCircle.setOutlineColor(Color::Black);
        gun.setOutlineColor(Color::Black);
        gun.setFillColor(Color(128, 128, 128));
        cout << "Player respawned" << endl;
    }
}

void Player::move()
{
    //sprite.setPosition(position);
    
    if(isAlive) playerCircle.setPosition(position);
	if(isAlive) gun.setPosition(position);
	
}

void Player::draw(RenderWindow& window)
{
   // window.draw(sprite);
    

    
    window.draw(playerCircle);
    window.draw(gun);

}
void Player::TakeDamage(float value)
{
    cout << "Player takes damage!" << endl;
	health -= value;
    playerCircle.setFillColor(Color::Red);
	gun.setFillColor(Color::Red);
    Clock clock;
    while (clock.getElapsedTime().asSeconds() < 1.f)
    {
        // Wait for 2 seconds
    }
    playerCircle.setFillColor(Color(255, 220, 180));
	gun.setFillColor(Color(128, 128, 128));
	if (health < 0)
	{
		health = 0;
	}
    if (health == 0) 
    {
        playerCircle.setFillColor(Color::Transparent);
        gun.setFillColor(Color::Transparent);
		playerCircle.setOutlineColor(Color::Transparent);
		gun.setOutlineColor(Color::Transparent);
		isAlive = false;
		cout << "Player is dead!" << endl;
    }
}
Vector2f Player::getPlayerPosition()
{
    return position;
}

void Player::setPlayerPosition(float x, float y)
{
    position = Vector2f(x, y);
    move();
}

string Player::get_name()
{
    return name;
}

void Player::set_name(string _name)
{
    name = _name;
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
ostream& operator<<(ostream& out, Player& player)
{
    out << player.toStr();
    return out;
}
