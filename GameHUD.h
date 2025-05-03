#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "HealthBar.h"
#include "CollectibleSpawner.h"
using namespace sf;
using namespace std;
class GameHUD
{
private:
	HealthBar * healthBar;
	Sprite armorSprite;
	Sprite fireRateSprite;

	static Texture armorTexture;
	static Texture fireRateTexture;

	static Font textFont;
	Text armorCountText;
	Text fireRateCountText;
public:
	
	GameHUD();
	~GameHUD();
	void Update(CollectibleSpawner &spawner, RenderWindow& window, float health, float maxHealth, int score, int highScore, float totalTime, Text TimerText, Text ScoreText, Text HighScoreText);
	void Draw(RenderWindow& window, Text ScoreText, Text HighScoreText, Text TimerText);
};

