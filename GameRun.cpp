#include "GameRun.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "Player.h"
#include "MapLimit.h"
#include "Bullet.h"
#include "GameException.h"
#include "HealthBar.h"
#include "Character.h"
#include "EnemySpawner.h"
using namespace std;
using namespace sf;
GameRun::GameRun()
{
	window = new RenderWindow(VideoMode::getDesktopMode(), "Zombie Invasion Survival");
	background = new Background();
	player = new Player("Aditzuu", 100.f, 100.f, true, 100.f, 100.f, 2.f);
	enemySpawner = new EnemySpawner();
	gameHUD = new GameHUD();
	MapLimit rightLimit(1350, 0, 20, 768);
	limits[0] = new MapLimit (0, 0, 1366, 20);
	limits[1] = new MapLimit (0, 768, 1366, 20);
	limits[2] = new MapLimit (0, 0, 20, 768);
	limits[3] = new MapLimit (1366, 0, 20, 768);


	
	cout << "App is running..." << endl;
	cout << player << endl;
}
GameRun::~GameRun()
{
	delete window;
	delete background;
	delete player;
	delete gameHUD;
	delete enemySpawner;
	for (int i = 0;i < 4;i++)
	{
		delete limits[i];
	}
}
void GameRun::Run() {
	
    Font font;
	if (!font.openFromFile("E:\\ProiectPOO\\ProiectPOO\\Pixeboy-z8XGD.ttf")) 
    {
		throw GameException("Font not found");
	}
	const int targetFPS = 60; // Change to 30 for 30 FPS
	const float frameTime = 1.0f / targetFPS;
    Text ScoreText(font);
	ScoreText.setCharacterSize(50);
	ScoreText.setFillColor(Color::White);
	ScoreText.setOutlineColor(Color::Black);
	ScoreText.setOutlineThickness(2.f);
	ScoreText.setPosition(Vector2f(15.f, 710.f));
	ScoreText.setString("Score: 0");

	Text HighScoreText(font);
	HighScoreText.setCharacterSize(50);
	HighScoreText.setFillColor(Color::White);
	HighScoreText.setOutlineColor(Color::Black);
	HighScoreText.setOutlineThickness(2.f);
	HighScoreText.setPosition(Vector2f(15.f, 660.f));
	HighScoreText.setString("High score: 0");

	Text TimerText(font);
	TimerText.setCharacterSize(50);
	TimerText.setFillColor(Color::White);
	TimerText.setOutlineColor(Color::Black);
	TimerText.setOutlineThickness(2.f);
	TimerText.setPosition(Vector2f(683.f, 10.f));
	TimerText.setString("0:00");
	Clock clock;
	float totalTime = 0.f;
    while (window->isOpen()) {
		
		Time elapsed = clock.restart();
		float deltaTime = elapsed.asSeconds();
		if (player->get_state()) totalTime += deltaTime;
		else {
			totalTime = 0.f;
			enemySpawner->ResetTime();
		}
		if (player->getScoreCount() > 65
			) 
		{ 
		player->ResetScoreCount();
		enemySpawner->DecreaseTime();
		}
        while (const optional event = window->pollEvent()) {
            if (event->is<Event::Closed>())
                window->close();
        }
        player->Update();
        player->handleInput(*window);
        player->move();
        for (int i = 0; i < 4; i++) {
            if (limits[i]->checkCollision(*player)) {
                player->goBack();
            }
        }
		ScoreText.setString("Score:" + to_string(player->getScore()));
		HighScoreText.setString("High score:" + to_string(player->getHighScore()));
		
        window->clear(Color(200, 200, 200));
		background->draw(*window);

        player->draw(*window);
		
		enemySpawner->Update(*player, *window);
		gameHUD->Update(*window, player->getHealth(), player->getMaxHealth(), player->getScore(), player->getHighScore(), totalTime, TimerText, ScoreText, HighScoreText);
     
        for (int i = 0; i < 4; i++) {
            limits[i]->draw(*window);
        }
        window->display();
		float sleepTime = frameTime - deltaTime;
		if (sleepTime > 0) {
			this_thread::sleep_for(chrono::duration<float>(sleepTime));
		}
    }
    cout << "App is closing..." << endl;
}

