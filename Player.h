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
    Vector2f position;
    CircleShape playerCircle;  
    RectangleShape gun; 
    char buff[250];
    

public:
    Player(string _name="nd", float x = 0, float y = 0, float _speed = 0);

    void handleInput();
    void move();
    void draw(RenderWindow& window);

    Vector2f getPlayerPosition();
    void setPlayerPosition(float x, float y);
    string get_name();
    void set_name(string name);
    char* toStr();
	friend ostream& operator<<(ostream& out, Player& player);
	
};
