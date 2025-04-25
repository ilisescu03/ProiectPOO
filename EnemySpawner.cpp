#include "EnemySpawner.h"  
#include <random>
#include <vector>  
#include <iostream>  
#include "Enemy.h"  
#include "Player.h"
using namespace std;  
EnemySpawner::EnemySpawner()  
{  
   spawnTime = 8.f;  
}  
void EnemySpawner::ResetTime()
{
	spawnTime = 8.f;
}
void EnemySpawner::DecreaseTime()
{
    spawnTime /= 1.27f;
	if (spawnTime < 1.f) spawnTime = 1.f;
}
void EnemySpawner::Update(Player &player, RenderWindow& window)
{  
	if (!player.get_state()) ClearVector();
	if (SpawnClock.getElapsedTime().asSeconds() >= spawnTime&&enemies.size()<=20)
	{
		SpawnClock.restart();
		enemies.push_back(Enemy(getRandomX(), getRandomY()));
	}
    for (auto it = enemies.begin(); it != enemies.end();)
    {
        if (it->GetState())
        {
            it = enemies.erase(it); // Remove from the list
            player.IncreaseScore(15);
        }
        else
        {
            it->Update(player);
            it->Draw(window);
            ++it;
        }
    }

    for (auto& bullet : player.getBullets()) {
        for (auto& enemy : enemies) {
            if (!enemy.GetState() && enemy.Collides(bullet)) {
                enemy.TakeDamage(10);
                bullet.Destroy();
            }
        }
    }
   
}  
float EnemySpawner::getRandomX()  
{  
    random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> distrib(0.f, 1366.f);
	return distrib(gen);
   
}  
float EnemySpawner::getRandomY()  
{  
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> distrib(0.f, 768.f);
    return distrib(gen);
}
void EnemySpawner::ClearVector()
{
	enemies.clear();
}