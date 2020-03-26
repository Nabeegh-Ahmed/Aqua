#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameEngine.h"
#include<stdlib.h>
#include<time.h>
int main() {
	srand(time(NULL));
    GameEngine g;
    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
    sf::RectangleShape shape1(sf::Vector2f(200.f, 200.f));
	shape1.setPosition(10, 10);
	sf::Vector2f PointOfStart(20,500);
	float spacebetweenshapes = 130;
	sf::RectangleShape Shape3(sf::Vector2f(30.0f, 100.0f));
	sf::Vector2f startingposition2(0, 100);
    sf::RectangleShape shape2(sf::Vector2f(50.f, 250.f));
	shape2.setFillColor(sf::Color::Blue);
	sf::RectangleShape base(sf::Vector2f(window.getSize().x*20, 50));
	base.setPosition(0, 440);
    CollisionSide collisions;
	sf::View view2(sf::Vector2f(350.f, 300.f), sf::Vector2f(900.f, 900.f));
    while (window.isOpen())
    {
        sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}
		g.ShapeRepeater(shape1, shape2, window, startingposition2, spacebetweenshapes);
		g.ShapeRepeater(shape1,shape2, window, PointOfStart, spacebetweenshapes);
		g.enableMovement(shape1);
		g.moveView(shape1, view2);
		collisions=g.areColliding(shape1, base);
		g.Gravity(shape1, collisions);
		window.setView(view2);
		window.draw(shape1);
		window.draw(base);
        window.display();   
		window.clear();
    }
    return 0;
}
