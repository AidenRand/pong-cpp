#ifndef NET_HPP
#define NET_HPP

#include <SFML/Graphics.hpp>

class Net
{
public:
	Net(float width, float height)
	{
		rect1.setSize(sf::Vector2f(width, height));
		rect1.setPosition(490, 32);
		rect1.setFillColor(sf::Color(200, 200, 200));

		rect2.setSize(sf::Vector2f(width, height));
		rect2.setPosition(490, 57);
		rect2.setFillColor(sf::Color(200, 200, 200));

		rect3.setSize(sf::Vector2f(width, height));
		rect3.setPosition(490, 82);
		rect3.setFillColor(sf::Color(200, 200, 200));

		rect4.setSize(sf::Vector2f(width, height));
		rect4.setPosition(490, 107);
		rect4.setFillColor(sf::Color(200, 200, 200));

		rect5.setSize(sf::Vector2f(width, height));
		rect5.setPosition(490, 132);
		rect5.setFillColor(sf::Color(200, 200, 200));

		rect6.setSize(sf::Vector2f(width, height));
		rect6.setPosition(490, 157);
		rect6.setFillColor(sf::Color(200, 200, 200));

		rect7.setSize(sf::Vector2f(width, height));
		rect7.setPosition(490, 182);
		rect7.setFillColor(sf::Color(200, 200, 200));

		rect8.setSize(sf::Vector2f(width, height));
		rect8.setPosition(490, 207);
		rect8.setFillColor(sf::Color(200, 200, 200));

		rect9.setSize(sf::Vector2f(width, height));
		rect9.setPosition(490, 232);
		rect9.setFillColor(sf::Color(200, 200, 200));

		rect10.setSize(sf::Vector2f(width, height));
		rect10.setPosition(490, 257);
		rect10.setFillColor(sf::Color(200, 200, 200));

		rect11.setSize(sf::Vector2f(width, height));
		rect11.setPosition(490, 282);
		rect11.setFillColor(sf::Color(200, 200, 200));

		rect12.setSize(sf::Vector2f(width, height));
		rect12.setPosition(490, 307);
		rect12.setFillColor(sf::Color(200, 200, 200));

		rect13.setSize(sf::Vector2f(width, height));
		rect13.setPosition(490, 332);
		rect13.setFillColor(sf::Color(200, 200, 200));

		rect14.setSize(sf::Vector2f(width, height));
		rect14.setPosition(490, 357);
		rect14.setFillColor(sf::Color(200, 200, 200));

		rect15.setSize(sf::Vector2f(width, height));
		rect15.setPosition(490, 382);
		rect15.setFillColor(sf::Color(200, 200, 200));

		rect16.setSize(sf::Vector2f(width, height));
		rect16.setPosition(490, 407);
		rect16.setFillColor(sf::Color(200, 200, 200));

		rect17.setSize(sf::Vector2f(width, height));
		rect17.setPosition(490, 432);
		rect17.setFillColor(sf::Color(200, 200, 200));

		rect18.setSize(sf::Vector2f(width, height));
		rect18.setPosition(490, 457);
		rect18.setFillColor(sf::Color(200, 200, 200));

		rect19.setSize(sf::Vector2f(width, height));
		rect19.setPosition(490, 482);
		rect19.setFillColor(sf::Color(200, 200, 200));

		rect20.setSize(sf::Vector2f(width, height));
		rect20.setPosition(490, 507);
		rect20.setFillColor(sf::Color(200, 200, 200));

		rect21.setSize(sf::Vector2f(width, height));
		rect21.setPosition(490, 532);
		rect21.setFillColor(sf::Color(200, 200, 200));

		rect22.setSize(sf::Vector2f(width, height));
		rect22.setPosition(490, 557);
		rect22.setFillColor(sf::Color(200, 200, 200));
	}

	void drawTo(sf::RenderWindow& window)
	{
		window.draw(rect1);
		window.draw(rect2);
		window.draw(rect3);
		window.draw(rect4);
		window.draw(rect5);
		window.draw(rect6);
		window.draw(rect7);
		window.draw(rect8);
		window.draw(rect9);
		window.draw(rect10);
		window.draw(rect11);
		window.draw(rect12);
		window.draw(rect13);
		window.draw(rect14);
		window.draw(rect15);
		window.draw(rect16);
		window.draw(rect17);
		window.draw(rect18);
		window.draw(rect19);
		window.draw(rect20);
		window.draw(rect21);
		window.draw(rect22);
	}

private:
	sf::RectangleShape rect1;
	sf::RectangleShape rect2;
	sf::RectangleShape rect3;
	sf::RectangleShape rect4;
	sf::RectangleShape rect5;
	sf::RectangleShape rect6;
	sf::RectangleShape rect7;
	sf::RectangleShape rect8;
	sf::RectangleShape rect9;
	sf::RectangleShape rect10;
	sf::RectangleShape rect11;
	sf::RectangleShape rect12;
	sf::RectangleShape rect13;
	sf::RectangleShape rect14;
	sf::RectangleShape rect15;
	sf::RectangleShape rect16;
	sf::RectangleShape rect17;
	sf::RectangleShape rect18;
	sf::RectangleShape rect19;
	sf::RectangleShape rect20;
	sf::RectangleShape rect21;
	sf::RectangleShape rect22;
};

#endif