#ifndef GAME_LOGIC_HPP
#define GAME_LOGIC_HPP

#include <SFML/Graphics.hpp>
#include <ball.hpp>
#include <iostream>
#include <string>

class Logic
{
public:
	Logic(std::string leftScoreText, std::string rightScoreText, sf::Font font)
	{
		leftScore.setFont(font);
		rightScore.setFont(font);
		leftScore.setString(leftScoreText);
		rightScore.setString(rightScoreText);
	};

	void drawScore(sf::RenderWindow& window)
	{
		window.draw(leftScore);
		window.draw(rightScore);
	}

private:
	sf::Text leftScore;
	sf::Text rightScore;
};

#endif