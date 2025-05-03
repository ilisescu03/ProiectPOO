#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class GameOverMenu {
private:
    sf::RectangleShape background;
    sf::Text retryButton;
    sf::Text exitButton;
	sf::Text pressR;
	sf::Text highScoreText;
	sf::Text scoreText;

    static sf::Font font;
    bool hidden = false;

public:
    GameOverMenu(sf::RenderWindow& window);
	void hide();
    void show();

    void draw(sf::RenderWindow& window, int score, int highscore);
    
};
