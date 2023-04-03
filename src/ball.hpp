#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball
{
public:
	// Make the ball
	Ball(float width, float height, float x, float y)
	{
		rect.setSize(sf::Vector2f(width, height));
		rect.setFillColor(sf::Color(220, 220, 220));
		rect.setOrigin(height / 2, width / 2);
		rect.setPosition(x, y);
	}

	void update()
	{
		// If the ball hits the left or right side reverse the direction
		if (rect.getPosition().x > 995)
		{
			stepx -= 5;
		}
		else if (rect.getPosition().x < 5)
		{
			stepx += 5;
		}

		// If the ball hits the top or bottom side reverse the direction
		if (rect.getPosition().y > 595)
		{
			stepy -= 5;
		}
		else if (rect.getPosition().y < 5)
		{
			stepy += 5;
		}
	}

	// Draw the ball to the window
	void draw_to(sf::RenderWindow& window)
	{
		rect.move(stepx, stepy);
		window.draw(rect);
	}

private:
	sf::RectangleShape rect;
	float stepx = 6;
	float stepy = 5;
};

#endif