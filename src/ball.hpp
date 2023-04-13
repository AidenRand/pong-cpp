#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <paddles.hpp>

class Ball
{
public:
	// Make ball
	Ball(float width, float height, float x, float y, sf::Texture& texture)
	{
		rect.setTexture(texture);
		rect.scale(sf::Vector2f(width, height));
		rect.setOrigin(height / 2, width / 2);
		rect.setPosition(x, y);
	}

	sf::Sprite rect;

	void paddleCollision(Paddles& left, Paddles& right)
	{
		auto leftPaddle = left.leftPaddle;
		auto rightPaddle = right.rightPaddle;

		// When ball hits paddle, reverse the x speed
		if (rect.getGlobalBounds().intersects(leftPaddle.getGlobalBounds()))
		{
			stepx = 12;
		}

		if (rect.getGlobalBounds().intersects(rightPaddle.getGlobalBounds()))
		{
			stepx = -12;
		}
	}

	void update()
	{
		// If ball hits top or bottom, reverse y speed
		if (rect.getPosition().y >= 550)
		{
			stepy -= 5;
		}
		else if (rect.getPosition().y <= 10)
		{
			stepy += 5;
		}
	}

	void resetBall()
	{
		int randomStepX = 6 + (rand() % 7);
		int randomStepY = 5;
		int delay = 1;
		delay *= CLOCKS_PER_SEC;
		clock_t now = clock();

		// If ball goes past left or right window boundary, reset ball at center
		if (rect.getPosition().x > 1050)
		{
			rect.setPosition(494, 240);
			while (clock() - now < delay)
				; // Empty while
			stepx = -randomStepX;
			stepy = -randomStepY;
		}
		else if (rect.getPosition().x < -50)
		{
			rect.setPosition(494, 240);
			while (clock() - now < delay)
				; // Empty while
			stepx = randomStepX;
			stepy = randomStepY;
		}
	}

	void endGame()
	{
		rect.setPosition(485, 290);
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