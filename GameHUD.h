#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "HealthBar.h"
using namespace sf;
using namespace std;
class GameHUD
{
private:
	HealthBar * healthBar;
public:
	
	GameHUD();
	~GameHUD();
	void Update(RenderWindow& window, float health, float maxHealth, int score, int highScore, float totalTime, Text TimerText, Text ScoreText, Text HighScoreText);
	void Draw(RenderWindow& window, Text ScoreText, Text HighScoreText, Text TimerText);
};

