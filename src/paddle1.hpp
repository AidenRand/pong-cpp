#ifndef PADDLE1_H
#define PADDLE1_H

#include <SFML/Graphics.hpp>

class Paddle
{
public:
	Paddle(float width, float height, float x, float y)
	{
		rect.setSize(sf::Vector2f(width, height));
		rect.setPosition(x, y);
		rect.setOrigin(width / 2, height / 2);
		up = false;
		down = false;
	}

	void processEvents(sf::Keyboard::Key key, bool checkPressed)
	{
		if (checkPressed == true)
		{
			if (key == sf::Keyboard::S)
			{
				up = true;
			}

			if (key == sf::Keyboard::W)
			{
				down = true;
			}
		}

		if (checkPressed == false)
		{
			up = false;
			down = false;
		}
	}

	void update()
	{
		sf::Vector2f movement;
		if (up)
		{
			movement.y = 15.0;
			if (rect.getPosition().y >= 575)
			{
				movement.y -= 15.0;
			}
		}

		if (down)
		{
			movement.y = -15.0;
			if (rect.getPosition().y <= 25)
			{
				movement.y += 15.0;
			}
		}

		rect.move(movement);
	}

	void draw_to(sf::RenderWindow& window)
	{
		window.draw(rect);
	}

private:
	sf::RectangleShape rect;
	bool up;
	bool down;
};

#endif
