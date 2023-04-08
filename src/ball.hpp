#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <paddles.hpp>
#include <unistd.h>

class Ball
{
public:
	// Make ball
	Ball(float width, float height, float x, float y)
	{
		rect.setSize(sf::Vector2f(width, height));
		rect.setFillColor(sf::Color(200, 200, 200));
		rect.setOrigin(height / 2, width / 2);
		rect.setPosition(x, y);
	}

	sf::RectangleShape rect;

	void paddleCollision(Paddles& left, Paddles& right)
	{
		auto leftPaddle = left.leftPaddle;
		auto rightPaddle = right.rightPaddle;

		// When ball hits paddle, reverse the x speed
		if (rect.getGlobalBounds().intersects(leftPaddle.getGlobalBounds()))
		{
			stepx = 14;
		}

		if (rect.getGlobalBounds().intersects(rightPaddle.getGlobalBounds()))
		{
			stepx = -14;
		}
	}

	void update()
	{
		// If ball hits top or bottom, reverse y speed
		if (rect.getPosition().y > 595)
		{
			stepy -= 5;
		}
		else if (rect.getPosition().y < 5)
		{
			stepy += 5;
		}
	}

	void resetBall()
	{
		int randomStepX = 6 + (rand() % 7);
		int randomStepY = 5;

		// If ball goes past left or right window boundary, reset ball at center
		if (rect.getPosition().x > 1005)
		{
			rect.setPosition(494, 240);
			sleep(1);
			stepx = -randomStepX;
			stepy = -randomStepY;
		}
		else if (rect.getPosition().x < -5)
		{
			rect.setPosition(494, 240);
			sleep(1);
			stepx = randomStepX;
			stepy = randomStepY;
		}
	}

	// Draw ball to the window
	void drawTo(sf::RenderWindow& window)
	{
		rect.move(stepx, stepy);
		window.draw(rect);
	}

private:
	float stepx = 6;
	float stepy = 5;
};

#endif