#include "GameOverMenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Window.hpp>
using namespace sf;
using namespace std;
Font GameOverMenu::font("E:\\ProiectPOO\\ProiectPOO\\Pixeboy-z8XGD.ttf");
GameOverMenu::GameOverMenu(sf::RenderWindow& window):retryButton(font), exitButton(font), pressR(font), scoreText(font), highScoreText(font) {
    // Load font
   

    // Set up background
    background.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    background.setFillColor(sf::Color(128, 128, 128, 255)); // Semi-transparent gray

    // Set up "Retry" button

    retryButton.setString("Retry");
    retryButton.setCharacterSize(50);
    retryButton.setFillColor(sf::Color(64, 64, 64)); // Dark gray text
    retryButton.setPosition(Vector2f(window.getSize().x / 2.f - 100.f, window.getSize().y / 2.f - 100.f));

    // Set up "Exit" button

    exitButton.setString("Exit");
    exitButton.setCharacterSize(50);
    exitButton.setFillColor(sf::Color(64, 64, 64)); // Dark gray text
    exitButton.setPosition(Vector2f(window.getSize().x / 2.f - 100.f, window.getSize().y / 2.f + 50.f));

	// Set up "Press R" text
	pressR.setString("Press R to restart");
	pressR.setCharacterSize(50);
	pressR.setFillColor(sf::Color(64, 64, 64)); // Dark gray text
	pressR.setPosition(Vector2f(window.getSize().x / 2.f - 100.f, window.getSize().y / 2.f -100.f));

	// Set up "High Score" text
	highScoreText.setString("High Score: 0");
	highScoreText.setCharacterSize(50);
	highScoreText.setFillColor(sf::Color(64, 64, 64)); // Dark gray text
	highScoreText.setPosition(Vector2f(window.getSize().x / 2.f - 100.f, window.getSize().y / 2.f + 200.f));

	// Set up "Score" text
	scoreText.setString("Score: 0");
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color(64, 64, 64)); // Dark gray text
	scoreText.setPosition(Vector2f(window.getSize().x / 2.f - 100.f, window.getSize().y / 2.f + 250.f));
	// Set up the initial state
	hidden = true; // Initially hidden
	background.setFillColor(sf::Color(0, 0, 0, 0)); // Make background invisible
	
}

void GameOverMenu::draw(sf::RenderWindow& window, int score, int highscore) {
	highScoreText.setString("High Score: " + std::to_string(highscore));
	scoreText.setString("Score: " + std::to_string(score));
    window.draw(background);
 //   window.draw(retryButton);
  //  window.draw(exitButton);
	window.draw(pressR);
	window.draw(highScoreText);
	window.draw(scoreText);
	
}
void GameOverMenu::hide() {
	background.setFillColor(sf::Color(0, 0, 0, 0)); // Make background invisible
	retryButton.setFillColor(sf::Color(0, 0, 0, 0)); // Make "Retry" button invisible
	exitButton.setFillColor(sf::Color(0, 0, 0, 0)); // Make "Exit" button invisible
	pressR.setFillColor(sf::Color(0, 0, 0, 0)); // Make "Press R" text invisible
	highScoreText.setFillColor(sf::Color(0, 0, 0, 0)); // Make "High Score" text invisible
	scoreText.setFillColor(sf::Color(0, 0, 0, 0)); // Make "Score" text invisible
	hidden = true; // Set hidden to true
}
void GameOverMenu::show() {
	background.setFillColor(sf::Color(128, 128, 128, 255)); // Make background visible
	retryButton.setFillColor(sf::Color(64, 64, 64)); // Make "Retry" button visible
	exitButton.setFillColor(sf::Color(64, 64, 64)); // Make "Exit" button visible
	pressR.setFillColor(sf::Color(64, 64, 64)); // Make "Press R" text visible
	highScoreText.setFillColor(sf::Color(64, 64, 64)); // Make "High Score" text visible
	scoreText.setFillColor(sf::Color(64, 64, 64)); // Make "Score" text visible
	hidden = false; // Set hidden to false
}
