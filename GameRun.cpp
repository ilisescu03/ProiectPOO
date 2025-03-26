#include "GameRun.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "MapLimit.h"
#include "Bullet.h"
#include "GameException.h"
#include "HealthBar.h";
#include "EnemySpawner.h"
using namespace std;
using namespace sf;
GameRun::GameRun()
{
	window = new RenderWindow(VideoMode({ 1366, 768 }), "Zombie Invasion Survival");
	player = new Player("Aditzuu", 100.f, 100.f, true, 100.f, 100.f, 2.f);
	healthbar = new HealthBar(1366, 768);
	enemySpawner = new EnemySpawner();
	
	MapLimit rightLimit(1350, 0, 20, 768);
	limits[0] = new MapLimit (0, 0, 1366, 20);
	limits[1] = new MapLimit (0, 750, 1366, 20);
	limits[2] = new MapLimit (0, 0, 20, 768);
	limits[3] = new MapLimit (1350, 0, 20, 768);


	
	cout << "App is running..." << endl;
	cout << player << endl;
}
GameRun::~GameRun()
{
	delete window;
	delete player;
	for (int i = 0;i < 4;i++)
	{
		delete limits[i];
	}
}
void GameRun::Run() {
    while (window->isOpen()) {
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

        window->clear(Color(200, 200, 200));
        healthbar->Update(player->getHealth(), player->getMaxHealth());
        player->draw(*window);

		enemySpawner->Update(*player, *window);

        healthbar->draw(*window);
        for (int i = 0; i < 4; i++) {
            limits[i]->draw(*window);
        }
        window->display();
    }
    cout << "App is closing..." << endl;
}

