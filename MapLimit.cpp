#include "MapLimit.h"
#include "GameException.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;
MapLimit::MapLimit(float x, float y, float width, float height)
{
	limit.setFillColor(Color::Transparent);
	limit.setSize(Vector2f(width, height));
	limit.setPosition(Vector2f(x, y));
}
void MapLimit::draw(RenderWindow& window)
{
	window.draw(limit);
}
bool MapLimit::checkCollision(Player& player)
{
	RectangleShape playerCollider = player.getPlayerCollider();
	RectangleShape limitCollider = limit;

	Vector2f pos1 = player.getPlayerCollider().getPosition();
	Vector2f size1 = player.getPlayerCollider().getSize();
	Vector2f pos2 = limit.getPosition();
	Vector2f size2 = limit.getSize();

	bool collisionX = (pos1.x + size1.x >= pos2.x) && (pos2.x + size2.x >= pos1.x);
	bool collisionY = (pos1.y + size1.y >= pos2.y) && (pos2.y + size2.y >= pos1.y);

	return collisionX && collisionY;


}