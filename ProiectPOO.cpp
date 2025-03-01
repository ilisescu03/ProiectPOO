
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

int main()
{

    RenderWindow window(VideoMode({ 800, 600 }), "SFML works!");
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);
    Texture texture;
    texture.loadFromFile("E:/player.png");
	Sprite image(texture);
    while (window.isOpen())
    {
        while (const optional event=window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.draw(image);
        window.display();
    }
}
