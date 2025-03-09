#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;
class HealthBar
{
private:
	RectangleShape BarBackground;
	RectangleShape BarFill;
public:
	HealthBar(float screenWidth=0, float screenHeight=0);
	void Update(float health, float maxHealth);
	void draw(RenderWindow& window);
};

