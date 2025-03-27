#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class GameHUD
{
private:

public:
	GameHUD();
	void Update(RenderWindow& window, int score, int health);
	void Draw(RenderWindow& window);
};

