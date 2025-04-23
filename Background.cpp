#include "Background.h"
Texture Background::_texture("E:\\ProiectPOO\\ProiectPOO\\BackgroundImage.png");
Background::Background() :
	_sprite(_texture)
{
	_sprite.setScale(Vector2f(1.1f, 1.1f));
	_sprite.setPosition(Vector2f(0.f, 0.f));
}

void Background::draw(RenderWindow& window)
{
	window.draw(_sprite);
}