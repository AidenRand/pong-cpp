#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Pong");
	window.setFramerateLimit(60);

	//  Draw ball
	float stepx = 5;
	float stepy = 5;

	sf::RectangleShape ball;
	ball.setSize(sf::Vector2f(10, 10));
	ball.setFillColor(sf::Color(240, 240, 240));
	ball.setOrigin(5, 5);
	ball.setPosition(495, 295);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		// If the ball hits the left or right side reverse the direction
		if (ball.getPosition().x > 995)
		{
			stepx = -5;
		}
		else if (ball.getPosition().x < 5)
		{
			stepx = 5;
		}

		if (ball.getPosition().y > 595)
		{
			stepy = -5;
		}
		else if (ball.getPosition().y < 5)
		{
			stepy = 5;
		}

		ball.move(stepx, stepy);
		window.clear();
		window.draw(ball);
		window.display();
	}
	return 0;
}