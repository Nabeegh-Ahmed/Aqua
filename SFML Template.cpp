#include <SFML/Graphics.hpp>
#include "GameEngine.h"
#include<iostream>
#include<string>



int main() {
    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
    sf::RectangleShape shape1(sf::Vector2f(100.f, 100.f));
	sf::RectangleShape base(sf::Vector2f(900, 50));
	base.setPosition(0, 800);
	CollisionSide shape1collisions;
    sf::Texture left;
    left.loadFromFile("assets\\left.png");
    sf::Texture right;
    right.loadFromFile("assets\\right.png");
	shape1collisions.bottom = false;
    
    shape1.setPosition(100.f, 100.f);
    sf::CircleShape shape(50.f);
	shape.setPosition(300, 50);
    shape.setFillColor(sf::Color::Blue);
    GameEngine g;
    CollisionSide collisions;
    sf::View view2(sf::Vector2f(0.f, 0.f), sf::Vector2f(900.f, 900.f));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (g.MouseClick(shape1, event.mouseButton)) {
            std::cout << "clicked";
        }
        g.enableMovement(shape1);
		g.Gravity(shape1, base);
        g.animation(shape1, &left, &right, &right, &right);
        window.clear();
        //window.draw(shape);
        window.draw(shape1);
		window.draw(base);
        //window.setView(view2);
        window.display();   
    }
    return 0;
}