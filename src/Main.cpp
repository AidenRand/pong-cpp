#include <SFML/Graphics.hpp>

#include <ball.hpp>
#include <net.hpp>
#include <paddle1.hpp>
#include <paddle2.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "PONG");
	window.setFramerateLimit(60);

	// Create ball
	Ball ball(10, 10, 595, 295);

	// Create player paddles
	Paddle1 paddle1(10, 40, 20, 280);
	Paddle2 paddle2(10, 40, 980, 280);

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
				paddle1.processEvents(event.key.code, true);
			}
			else if (event.type == sf::Event::KeyReleased)
			{
				paddle1.processEvents(event.key.code, false);
			}

			// Check if up or down arrow has been pressed
			if (event.type == sf::Event::KeyPressed)
			{
				paddle2.processEvents(event.key.code, true);
			}
			else if (event.type == sf::Event::KeyReleased)
			{
				paddle2.processEvents(event.key.code, false);
			}
		}

		window.clear(sf::Color(6, 6, 6));
		ball.update();
		ball.draw_to(window);
		paddle1.update();
		paddle1.drawTo(window);
		paddle2.update();
		paddle2.drawTo(window);
		net.drawTo(window);
		net.drawTo(window);
		window.display();
	}
	return 0;
}