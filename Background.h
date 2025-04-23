#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class Background
{
private:
	static Texture _texture;
	Sprite _sprite;
public:
	Background();
	void draw(RenderWindow &window);
	
};

