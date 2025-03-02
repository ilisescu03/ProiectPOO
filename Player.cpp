#include "Player.h"
#include "GameException.h"
#include <iostream>
#include <string>

using namespace std;
Player::Player(string _name, float x, float y, float _speed) : name(_name), speed(_speed), position(Vector2f(x, y))
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

void Player::move()
{
    //sprite.setPosition(position);
    
    playerCircle.setPosition(position);
	gun.setPosition(position);
	
}

void Player::draw(RenderWindow& window)
{
   // window.draw(sprite);
    

    
    window.draw(playerCircle);
    window.draw(gun);

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
    sprintf_s(buff, "Player %s is at position: %f, %f", name.c_str(), position.x, position.y);
    return buff;
}

ostream& operator<<(ostream& out, Player& player)
{
    out << player.toStr();
    return out;
}
