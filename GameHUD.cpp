#include "GameHUD.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;
Texture GameHUD::armorTexture("E:\\ProiectPOO\\ProiectPOO\\Armor.png");
Texture GameHUD::fireRateTexture("E:\\ProiectPOO\\ProiectPOO\\FireRate.png");
Font GameHUD::textFont("E:\\ProiectPOO\\ProiectPOO\\Pixeboy-z8XGD.ttf");
GameHUD::GameHUD() : armorSprite(armorTexture), fireRateSprite(fireRateTexture), armorCountText(textFont), fireRateCountText(textFont)
{
	armorSprite.setColor(Color::Transparent);
	fireRateSprite.setColor(Color::Transparent);

	armorSprite.setScale(Vector2f(0.4f, 0.4f));     // armor = 40%
	fireRateSprite.setScale(Vector2f(0.2f, 0.2f));   // fireRate = 20%

	armorCountText.setCharacterSize(50);
	armorCountText.setFillColor(Color::Transparent);
	armorCountText.setOutlineColor(Color::Transparent);
	armorCountText.setOutlineThickness(2.f);

	fireRateCountText.setCharacterSize(50);
	fireRateCountText.setFillColor(Color::Transparent);
	fireRateCountText.setOutlineColor(Color::Transparent);
	fireRateCountText.setOutlineThickness(2.f);

	// DOAR modificăm valorile din paranteze:
	armorSprite.setPosition(Vector2f(460.f, 15.f));        // Armor sprite mai la stânga
	fireRateSprite.setPosition(Vector2f(530.f, 25.f));      // FireRate sprite puțin mai la dreapta

	armorCountText.setScale(Vector2f(0.5f, 0.5f));
	fireRateCountText.setScale(Vector2f(0.5f, 0.5f));

	armorCountText.setPosition(Vector2f(481.f, 60.f));      // Textul armor sub sprite-ul armor
	fireRateCountText.setPosition(Vector2f(540.f, 60.f));   // Textul fireRate sub sprite-ul fireRate

	healthBar = new HealthBar(1366, 768);
}


GameHUD::~GameHUD()
{
	delete healthBar;
}
void GameHUD::Update(CollectibleSpawner &spawner, RenderWindow& window, float health, float maxHealth, int score, int highScore, float totalTime, Text TimerText, Text ScoreText, Text HighScoreText)
{
	if (spawner.getArmorActive()) {
		armorSprite.setColor(Color::White);
		armorCountText.setFillColor(Color::White);
		armorCountText.setOutlineColor(Color::Black);
		int remainingTime = (int)(spawner.GetRemainingArmorTime());
		armorCountText.setString(to_string(remainingTime));

	}
	else {
		armorSprite.setColor(Color::Transparent);
		armorCountText.setFillColor(Color::Transparent);
		armorCountText.setOutlineColor(Color::Transparent);
	
	}
	if (spawner.getfireRateActive()) {
		fireRateSprite.setColor(Color::White);
		fireRateCountText.setFillColor(Color::White);
		fireRateCountText.setOutlineColor(Color::Black);
		int remainingTime = (int)(spawner.GetRemainingFireRateTime());
		fireRateCountText.setString(to_string(remainingTime));
	}
	else {
		fireRateSprite.setColor(Color::Transparent);
		fireRateCountText.setFillColor(Color::Transparent);
		fireRateCountText.setOutlineColor(Color::Transparent);
	
	}

	ScoreText.setString("Score: " + to_string(score));
	HighScoreText.setString("High score: " + to_string(highScore));
	int minutes = (int)totalTime / 60;
	int seconds = (int)totalTime % 60;
	if(minutes>9&&seconds>9) TimerText.setString(to_string(minutes) + ":" + to_string(seconds));
	if (minutes > 9 && seconds <= 9) TimerText.setString(to_string(minutes) + ":" + "0"+to_string(seconds));
	if (minutes <= 9 && seconds > 9) TimerText.setString("0"+to_string(minutes) + ":" + to_string(seconds));
	if (minutes <= 9 && seconds <= 9) TimerText.setString("0" + to_string(minutes) + ":" + "0" + to_string(seconds));
	Draw(window, ScoreText, HighScoreText, TimerText);
	healthBar->Update(window, health, maxHealth);

}
void GameHUD::Draw(RenderWindow& window, Text ScoreText, Text HighScoreText, Text TimerText)
{
	window.draw(ScoreText);
	window.draw(HighScoreText);
	window.draw(TimerText);
	window.draw(armorSprite);
	window.draw(fireRateSprite);
	window.draw(armorCountText);
	window.draw(fireRateCountText);

}