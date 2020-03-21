#include <SFML/Graphics.hpp>
#include "GameEngine.h"
#include<iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
    sf::RectangleShape shape1(sf::Vector2f(100.f, 100.f));
	sf::RectangleShape base(sf::Vector2f(900, 50));
	base.setPosition(0, 800);
	CollisionSide shape1collisions;
	shape1collisions.bottom = false;
    shape1.setFillColor(sf::Color::Red);
    shape1.setPosition(100.f, 100.f);
    sf::CircleShape shape(50.f);
	shape.setPosition(300, 50);
    shape.setFillColor(sf::Color::Blue);
    GameEngine g;
    CollisionSide collisions;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            shape.move(-0.01f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            shape.move(0.01f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            shape.move(0.f, -0.01f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            shape.move(0.f, 0.01f);
        }
        collisions = g.areColliding(shape, shape1);
        if (collisions.left)
            std::cout << "left" << std::endl;
        if (collisions.right)
            std::cout << "right" << std::endl;
        if (collisions.top)
            std::cout << "top" << std::endl;
        if (collisions.bottom)
            std::cout << "bottom" << std::endl;
		shape1collisions = g.areColliding(shape, base);
		g.Gravity(shape, shape1collisions);
        window.clear();
        window.draw(shape);
        window.draw(shape1);
		window.draw(base);
        window.display();
    }

    return 0;
}