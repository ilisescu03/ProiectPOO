#include "HealthBar.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


HealthBar::HealthBar(float screenWidth, float screenHeight)
{
    float barWidth = 300.f;
    float barHeight = 40.f;
    float padding = 3.f; 


    float xPos = screenWidth - barWidth - 80.f; 
    float yPos = screenHeight - barHeight - 40.f;


    BarBackground.setSize(Vector2f(barWidth, barHeight));
    BarBackground.setFillColor(Color::Black);
    BarBackground.setPosition(Vector2f(xPos, yPos));

 
    BarFill.setSize(Vector2f(barWidth - 2 * padding, barHeight - 2 * padding));
    BarFill.setFillColor(Color::Red);
    BarFill.setPosition(Vector2f(xPos + padding, yPos + padding));


    BarFill.setOrigin(Vector2f(0.f, 0.f));
}

void HealthBar::Update(RenderWindow& window, float health, float maxHealth)
{
    float healthPercent = health / maxHealth;
    healthPercent = std::max(0.f, std::min(1.f, healthPercent)); 


    BarFill.setScale(Vector2f(healthPercent, 1.f));
    draw(window);
}

void HealthBar::draw(RenderWindow& window)
{
    window.draw(BarBackground);
    window.draw(BarFill);
}
