#include "GameHUD.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;
GameHUD::GameHUD()
{
	healthBar = new HealthBar(1366, 768);
}
GameHUD::~GameHUD()
{
	delete healthBar;
}
void GameHUD::Update(RenderWindow& window, float health, float maxHealth, int score, int highScore, float totalTime, Text TimerText, Text ScoreText, Text HighScoreText)
{
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

}