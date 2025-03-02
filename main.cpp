
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Player.h"
#include "GameException.h"
using namespace std;
using namespace sf;

int main()
{
    
    RenderWindow window(VideoMode({ 1366, 768 }), "Zombie Invasion Survival");
	Player player("Aditzuu", 100.f, 100.f, 2.f);
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

		window.clear(Color(200, 200, 200));
		player.draw(window);
		window.display();
    }
	cout << "App is closing..." << endl;
}
