
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Player.h"
#include "MapLimit.h"
#include "GameException.h"
using namespace std;
using namespace sf;

int main()
{
    
    RenderWindow window(VideoMode({ 1366, 768 }), "Zombie Invasion Survival");
	Player player("Aditzuu", 100.f, 100.f, true, 100.f, 100.f, 2.f);
	MapLimit upLimit(0, 0, 1366, 20);
	MapLimit downLimit(0, 750, 1366, 20);
	MapLimit leftLimit(0, 0, 20, 768);
	MapLimit rightLimit(1350, 0, 20, 768);
	MapLimit * limits[4];
	limits[0] = &upLimit;
	limits[1] = &rightLimit;
	limits[2] = &leftLimit;
	limits[3] = &downLimit;
    cout << "App is running..."<<endl;
    cout << player << endl;
    while (window.isOpen())
    {
        while (const optional event=window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();
        }
		
		player.handleInput();
		player.move();
		
		for (int i = 0;i < 4;i++)
		{
			if (limits[i]->checkCollision(player))
			{
				player.goBack();
			}
		}
		window.clear(Color(200, 200, 200));
		
		player.draw(window);
		for (int i = 0;i < 4;i++)
		{
			limits[i]->draw(window);
		}
		window.display();
    }
	cout << "App is closing..." << endl;
}
