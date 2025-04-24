#pragma once
#include <SFML/Graphics.hpp>
#include "GameException.h"

#include <iostream>
#include <string>
using namespace sf;
using namespace std;

class Collectible
{

	bool isActive = true;
	string type;
	static Texture _texture;
	static Texture _texture1;
	static Texture _texture2;
	Sprite Icon;
	Vector2f position;
	CircleShape collider;
public:
	Collectible(string _type="nd", float x = 0, float y = 0);
	void Draw(RenderWindow& window);
	string GetType();
	void Update();
	bool Collides(const RectangleShape& playerCollider);
	void Destroy();
	bool GetState();
};

