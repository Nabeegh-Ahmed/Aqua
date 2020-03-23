#include <SFML/Graphics.hpp>
#include "GameEngine.h"
#include<iostream>
#include<string>



int main() {
    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
    sf::RectangleShape shape1(sf::Vector2f(200.f, 200.f));
    sf::RectangleShape shape2(sf::Vector2f(200.f, 200.f));
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
    sf::View view2(sf::Vector2f(350.f, 300.f), sf::Vector2f(500.f, 500.f));
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
        //g.enableMovement(shape1);
        g.enableMovement(shape1);
		g.Gravity(shape1, base);
        g.animation(shape1, &left, &right, &right, &right);
        g.moveView(shape1, view2);
        
        window.clear();
        window.draw(shape1);
        //window.draw(shape2);
		window.draw(base);
        window.setView(view2);
        window.display();   
    }
    return 0;
}