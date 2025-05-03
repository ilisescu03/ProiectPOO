#include "CollectibleSpawner.h"
#include <random>
CollectibleSpawner::CollectibleSpawner()
{

	minspawnTime = 40.f;
	maxspawnTime = 80.f;
}
void CollectibleSpawner::ResetTime()
{
	minspawnTime = 40.f;
	maxspawnTime = 80.f;
}
float CollectibleSpawner::getRandomTime()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> distrib(minspawnTime, maxspawnTime);
	return distrib(gen);
}
void CollectibleSpawner::DecreaseTime()
{
	
}
void CollectibleSpawner::ClearVector()
{
	Collectibles.clear();
}
bool CollectibleSpawner::getArmorActive()
{
	return armorActive;
}
bool CollectibleSpawner::getfireRateActive()
{
	return fireRateActive;
}
void CollectibleSpawner::Update(RenderWindow &window, Player &player)
{
	if (!player.get_state()) ClearVector();
	if (SpawnClock.getElapsedTime().asSeconds() >= getRandomTime() && Collectibles.size() <= 30 && player.getScore()>=500.f)
	{
		SpawnClock.restart();
		Collectibles.push_back(Collectible(getRandomType(), getRandomX(), getRandomY()));
	}
	if (armorActive && armorClock.getElapsedTime().asSeconds() >= 10.f)
	{
		player.setImmunity(false);
		armorActive = false;
	}
	if (fireRateActive && fireRateClock.getElapsedTime().asSeconds() >= 10.f)
	{
		player.setShootingCooldown(0.5f);
		fireRateActive = false;
	}
	for (auto it = Collectibles.begin(); it != Collectibles.end();)
	{
		if (!it->GetState())
		{
			it = Collectibles.erase(it); // Remove from the list
		}
		else
		{
			if (it->Collides(player.getPlayerCollider()))
			{
				if (it->GetType() == "Health")
				{
					player.Heal(20.f);
				}
				else if (it->GetType() == "Armor")
				{
					player.setImmunity(true);
					armorClock.restart();
					armorActive = true;
				}
				else if (it->GetType() == "FireRate")
				{
					player.setShootingCooldown(0.25f);
					fireRateClock.restart();
					fireRateActive = true;
				}
				it->Destroy();
			}
			
			it->Draw(window);
			++it;
		}
	}
}
float CollectibleSpawner::GetRemainingArmorTime()
{
	return 10.f - armorClock.getElapsedTime().asSeconds();
}
float CollectibleSpawner::GetRemainingFireRateTime()
{
	return 10.f - fireRateClock.getElapsedTime().asSeconds();
}
float CollectibleSpawner::getRandomX()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> distrib(0.f, 1366.f);
	return distrib(gen);
}
float CollectibleSpawner::getRandomY()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> distrib(0.f, 768.f);
	return distrib(gen);
}
string CollectibleSpawner::getRandomType()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distrib(0, 2);
	int randomValue = distrib(gen);
	switch (randomValue)
	{
	case 0:
		return "Health";
	case 1:
		return "Armor";
	case 2:
		return "FireRate";
	default:
		return "Health"; // Default case
	}
}