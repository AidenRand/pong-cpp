#ifndef GAME_LOGIC_HPP
#define GAME_LOGIC_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <paddles.hpp>
#include <string>
class Logic
{
public:
	Logic(int leftScoreNum, int rightScoreNum)
	{

		std::string leftScoreText = std::to_string(leftScoreNum);
		std::string rightScoreText = std::to_string(rightScoreNum);
		leftScore.setString(leftScoreText);
		leftScore.setPosition(390, 40);
		rightScore.setString(rightScoreText);
		rightScore.setPosition(570, 40);
	};

	void updateScore(Ball& ballRect, int& leftScoreNum, int& rightScoreNum)
	{
		// Return error if font file doesn't load
		if (!font.loadFromFile("content/fonts/8_bit_party(1)/8_bit_party.ttf"))
		{
			std::cout << "Error loading file" << std::endl;
			system("pause");
		}

		// Get ball object from ball.hpp
		auto ball = ballRect.rect;

		// Increment score for side that scored
		if (ball.getPosition().x > 1050)
		{
			leftScoreNum += 1;
		}
		else if (ball.getPosition().x < -50)
		{
			rightScoreNum += 1;
		}

		leftScore.setFont(font);
		rightScore.setFont(font);
		leftScore.setCharacterSize(50);
		rightScore.setCharacterSize(50);
		leftScore.setFillColor(sf::Color(200, 200, 200));
		rightScore.setFillColor(sf::Color(200, 200, 200));
	}

	void endGame(int& leftScoreNum, int& rightScoreNum, sf::RenderWindow& window)
	{

		sf::Text leftWon, rightWon;

		// Make left player score
		leftWon.setString("Player 1   has won");
		leftWon.setFont(font);
		leftWon.setCharacterSize(50);
		leftWon.setPosition(255, 250);
		leftWon.setFillColor(sf::Color(200, 200, 200));

		// Make right player score
		rightWon.setString("Player 2   has won");
		rightWon.setFont(font);
		rightWon.setCharacterSize(50);
		rightWon.setPosition(255, 250);
		rightWon.setFillColor(sf::Color(200, 200, 200));

		// Stop game when left or right player score reaches 11
		if (leftScoreNum >= 11)
		{
			window.draw(leftWon);
		}
		else if (rightScoreNum >= 11)
		{
			window.draw(rightWon);
		}
	}

	void drawScore(sf::RenderWindow& window)
	{
		window.draw(leftScore);
		window.draw(rightScore);
	}

private:
	sf::Text leftScore;
	sf::Text rightScore;
	sf::Font font;
};

#endif