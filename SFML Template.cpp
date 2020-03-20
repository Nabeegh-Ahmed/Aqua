#include <SFML/Graphics.hpp>
#include "GameEngine.h"
#include<iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
    sf::RectangleShape shape1(sf::Vector2f(100.f, 100.f));
    shape1.setFillColor(sf::Color::Red);
    shape1.setPosition(100.f, 100.f);
    sf::CircleShape shape(50.f);
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
            shape.move(-2.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            shape.move(2.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            shape.move(0.f, -2.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            shape.move(0.f, 2.f);
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
        window.clear();
        window.draw(shape);
        window.draw(shape1);
        window.display();
    }

    return 0;
}