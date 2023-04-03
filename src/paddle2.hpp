#ifndef PADDLE2_HPP
#define PADDLE2_HPP

class Paddle2
{
public:
	// Make the paddle
	Paddle2(float width, float height, float x, float y)
	{
		rect.setSize(sf::Vector2f(width, height));
		rect.setPosition(x, y);
		rect.setOrigin(width / 2, height / 2);
		up = false;
		down = false;
	}

	// Detect if the up or down key has been pressed
	void processEvents(sf::Keyboard::Key key, bool checkPressed)
	{
		if (checkPressed == true)
		{
			if (key == sf::Keyboard::Down)
			{
				up = true;
			}
			else if (key == sf::Keyboard::Up)
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

	// Update the position of the paddle
	void update()
	{
		sf::Vector2f movement;
		if (up)
		{
			movement.y = 15;
			if (rect.getPosition().y >= 575)
			{
				movement.y -= 15;
			}
		}

		if (down)
		{
			movement.y = -15;
			if (rect.getPosition().y <= 25)
			{
				movement.y += 15;
			}
		}

		rect.move(movement);
	}

	// Draw the paddle to the window
	void drawTo(sf::RenderWindow& window)
	{
		window.draw(rect);
	}

	// Initialize variables
private:
	sf::RectangleShape rect;
	bool up;
	bool down;
};

#endif