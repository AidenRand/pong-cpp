#ifndef PADDLES_HPP
#define PADDLES_HPP

#include <SFML/Graphics.hpp>

class Paddles
{
public:
	Paddles(float height, float width, float x, float y)
	{
		// Define left paddle components
		leftPaddle.setPosition(x, y);
		leftPaddle.setSize(sf::Vector2f(height, width));
		leftPaddle.setOrigin(height / 2, width / 2);
		leftPaddle.setFillColor(sf::Color(200, 200, 200));
		leftUp = false;
		leftDown = false;

		// Define right paddle components
		rightPaddle.setPosition(x, y);
		rightPaddle.setSize(sf::Vector2f(height, width));
		rightPaddle.setOrigin(height / 2, width / 2);
		rightPaddle.setFillColor(sf::Color(200, 200, 200));
		rightUp = false;
		rightDown = false;
	}

	sf::RectangleShape leftPaddle;
	sf::RectangleShape rightPaddle;

	void processLeftEvents(sf::Keyboard::Key key, bool checkPressed)
	{
		// Check if the left paddle is being controlled
		if (checkPressed == true)
		{
			if (key == sf::Keyboard::W)
			{
				leftDown = true;
			}
			else if (key == sf::Keyboard::S)
			{
				leftUp = true;
			}
		}

		if (checkPressed == false)
		{
			leftUp = false;
			leftDown = false;
		}
	}

	void processRightEvents(sf::Keyboard::Key key, bool checkPressed)
	{

		// Check if the right paddle is being controlled
		if (key == sf::Keyboard::Up)
		{
			rightDown = true;
		}
		else if (key == sf::Keyboard::Down)
		{
			rightUp = true;
		}

		if (checkPressed == false)
		{
			rightUp = false;
			rightDown = false;
		}
	}

	void updateLeft()
	{
		sf::Vector2f leftMovement;

		// Control the direction of the left paddle
		// and stop it at the top and bottom of window
		if (leftUp)
		{
			leftMovement.y += 15;
			if (leftPaddle.getPosition().y >= 580)
			{
				leftMovement.y -= 15;
			}
		}
		else if (leftDown)
		{
			leftMovement.y -= 15;
			if (leftPaddle.getPosition().y <= 20)
			{
				leftMovement.y += 15;
			}
		}

		leftPaddle.move(leftMovement);
	}

	void updateRight()
	{
		sf::Vector2f rightMovement;

		// Control the direction of the right paddle
		// and stop it at the top and bottom of window
		if (rightUp)
		{
			rightMovement.y += 15;
			if (rightPaddle.getPosition().y >= 580)
			{
				rightMovement.y -= 15;
			}
		}
		else if (rightDown)
		{
			rightMovement.y -= 15;
			if (rightPaddle.getPosition().y <= 20)
			{
				rightMovement.y += 15;
			}
		}

		rightPaddle.move(rightMovement);
	}

	// Draw left paddle to window
	void leftDrawTo(sf::RenderWindow& window)
	{
		window.draw(leftPaddle);
	}

	// Draw right paddle to window
	void rightDrawTo(sf::RenderWindow& window)
	{
		window.draw(rightPaddle);
	}

private:
	bool leftUp, leftDown;
	bool rightUp, rightDown;
};

#endif