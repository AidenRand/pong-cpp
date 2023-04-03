#include <SFML/Graphics.hpp>

#include <ball.hpp>
#include <paddle1.hpp>
#include <paddle2.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Pong");
	window.setFramerateLimit(60);

	Paddle1 paddle1(10, 50, 20, 275);
	Paddle2 paddle2(10, 50, 980, 275);

	Ball ball(10, 10, 595, 295);

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

			// Check if s or w has been pressed
			if (event.type == sf::Event::KeyPressed)
			{
				paddle2.processEvents(event.key.code, true);
			}
			else if (event.type == sf::Event::KeyReleased)
			{
				paddle2.processEvents(event.key.code, false);
			}
		}

		window.clear();
		ball.update();
		ball.draw_to(window);
		paddle1.update();
		paddle1.drawTo(window);
		paddle2.update();
		paddle2.drawTo(window);
		window.display();
	}
	return 0;
}