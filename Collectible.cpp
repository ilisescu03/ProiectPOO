#include "Collectible.h"
Texture Collectible::_texture("E:\\ProiectPOO\\ProiectPOO\\Health.png");
Texture Collectible::_texture1("E:\\ProiectPOO\\ProiectPOO\\Armor.png");
Texture Collectible::_texture2("E:\\ProiectPOO\\ProiectPOO\\FireRate.png");
Collectible::Collectible(string _type, float x, float y): Icon(_texture)
{
	type = _type;
	if(type=="Health")
	{
		Icon.setTexture(_texture);
	}
	else if (type == "Armor")
	{
		Icon.setTexture(_texture1);
	}
	else if (type == "FireRate")
	{
		Icon.setTexture(_texture2);
	}
	else
	{
		throw GameException("Collectible", "Collectible type not found");
	}
	
	Icon.setOrigin(Vector2f(80.f, 80.f));
	Icon.setScale(Vector2f(0.25f, 0.25f));
	position = Vector2f(x, y);
	collider.setRadius(20.f);
	collider.setFillColor(Color::Transparent);
	collider.setOrigin(Vector2f(20.f, 20.f));
	collider.setPosition(position);
	Icon.setPosition(position);
}
void Collectible::Draw(RenderWindow& window)
{
	window.draw(Icon);
	window.draw(collider);

}
void Collectible::Update()
{

}
bool Collectible::Collides(const RectangleShape& playerCollider)
{
	float distance = sqrt(pow(playerCollider.getPosition().x - collider.getPosition().x, 2) +
		pow(playerCollider.getPosition().y - collider.getPosition().y, 2));
	return distance < (playerCollider.getSize().x/2.f + collider.getRadius());
}
void Collectible::Destroy()
{
	isActive = false;
	Icon.setColor(Color::Transparent);
	cout << "Collectible destroyed" << endl;
}
bool Collectible::GetState()
{
	return isActive;
}
string Collectible::GetType()
{
	return type;
}