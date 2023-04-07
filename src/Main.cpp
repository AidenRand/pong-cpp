#include <SFML/Graphics.hpp>

#include <ball.hpp>
#include <net.hpp>
#include <paddles.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "PONG");
	window.setFramerateLimit(60);

	// Create player paddles
	Paddles leftPaddle(10, 40, 20, 280);
	Paddles rightPaddle(10, 40, 980, 280);

	// Create ball
	Ball ball(10, 10, 595, 295);

	// Draw dotted line
	Net net(3, 15);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			// Check if s or w has been pressed
			if (event.type == sf::Event::KeyPressed)
			{
				leftPaddle.processLeftEvents(event.key.code, true);
			}
			else if (event.type == sf::Event::KeyReleased)
			{
				leftPaddle.processLeftEvents(event.key.code, false);
			}

			// Check if up or down arrow has been pressed
			if (event.type == sf::Event::KeyPressed)
			{
				rightPaddle.processRightEvents(event.key.code, true);
			}
			else if (event.type == sf::Event::KeyReleased)
			{
				rightPaddle.processRightEvents(event.key.code, false);
			}
		}

		ball.paddleCollision(leftPaddle, rightPaddle);
		window.clear(sf::Color(6, 6, 6));
		ball.update();
		ball.drawTo(window);
		leftPaddle.updateLeft();
		leftPaddle.leftDrawTo(window);
		rightPaddle.updateRight();
		rightPaddle.rightDrawTo(window);
		net.drawTo(window);
		window.display();
	}
	return 0;
}