#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Bullet.h"
#include "Character.h"
using namespace std;
using namespace sf;

class Player : public Character
{
private:
    string name;
    
    float maxhealth;
   

    Clock shootClock;
    Clock damageClock;
    Bullet b;
	vector <Bullet> bullets;
   
    Vector2f lastMovement;
    Vector2f initialPosition;
    RectangleShape collider;
    CircleShape playerCircle;  
    RectangleShape gun; 
	bool isShooting = false;
  
    Clock damageCooldownClock;
    int score = 0;
    int highScore = 0;
    char buff[250];
    

public:
    Player(string _name="nd", float _health=100, float _maxhealth=100, bool _isAlive=true, float x = 0, float y = 0, float _speed = 0);
    bool getCanTakeDamage();
    void setCanTakeDamage(bool value);
    float getHealth();
    float getMaxHealth();
    void TakeDamage(float value);
    void Update();
    void Respawn();
    void IncreaseScore(int value);
    void Die();
    vector<Bullet>& getBullets();
    void handleInput(RenderWindow& window);
    void goBack();
    float get_angle();
    bool get_state();
	bool is_shooting();
	void set_isShooting(bool value);
    void shoot();
    void move();
    float getCircleRadius();
    void draw(RenderWindow& window);
    Vector2f getPlayerPosition();
	RectangleShape getPlayerCollider();
    void setPlayerPosition(float x, float y);
    string get_name();
    void set_name(string name);
    char* toStr();
    Player& operator=(Player& player);
	friend ostream& operator<<(ostream& out, Player& player);
	
};
