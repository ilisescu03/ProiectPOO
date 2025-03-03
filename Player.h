#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class Player
{
private:
    string name;
    string path;
    float speed;
    float health;
    float maxhealth;
    bool isAlive;
    Vector2f position;
    Vector2f lastMovement;
    Vector2f initialPosition;
    RectangleShape collider;
    CircleShape playerCircle;  
    RectangleShape gun; 
    char buff[250];
    

public:
    Player(string _name="nd", float _health=100, float _maxhealth=100, bool _isAlive=true, float x = 0, float y = 0, float _speed = 0);
    void TakeDamage(float value);
    void handleInput();
    void goBack();
    bool get_state();
    void move();
    void draw(RenderWindow& window);
    Vector2f getPlayerPosition();
	RectangleShape getPlayerCollider();
    void setPlayerPosition(float x, float y);
    string get_name();
    void set_name(string name);
    char* toStr();
	friend ostream& operator<<(ostream& out, Player& player);
	
};
