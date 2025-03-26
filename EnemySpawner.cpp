#include "EnemySpawner.h"  
#include <vector>  
#include <iostream>  
#include "Enemy.h"  
#include "Player.h"
using namespace std;  
EnemySpawner::EnemySpawner()  
{  
   spawnTime = 4.f;  
}  
void EnemySpawner::Update(Player &player, RenderWindow& window)
{  
	if (!player.get_state()) ClearVector();
	if (SpawnClock.getElapsedTime().asSeconds() >= spawnTime)
	{
		SpawnClock.restart();
		enemies.push_back(Enemy(500.f, 300.f));
	}
    for (auto it = enemies.begin(); it != enemies.end();)
    {
        if (it->GetState())
        {
            it = enemies.erase(it); // Remove from the list
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
   return 0;  
}  
float EnemySpawner::getRandomY()  
{  
   return 0;  
}
void EnemySpawner::ClearVector()
{
	enemies.clear();
}