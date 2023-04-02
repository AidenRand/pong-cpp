#include <SFML/Graphics.hpp>

#include <ball.hpp>
#include <paddle1.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Pong");
	window.setFramerateLimit(60);

	Paddle paddle1(10, 50, 20, 250);

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
		}

		window.clear();
		ball.update();
		ball.draw_to(window);
		paddle1.update();
		paddle1.draw_to(window);
		window.display();
	}
	return 0;
}