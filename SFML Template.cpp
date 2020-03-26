#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameEngine.h"

int main() {
    sf::Shader shader;
    shader.loadFromFile("vertex_shader.vert", "fragment_shader.frag");
    shader.setUniform("hasTexture", true);
    shader.setUniform("lightPos", sf::Vector2f(50.f, 50.f));
    
    GameEngine g;
    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
    sf::RectangleShape shape1(sf::Vector2f(200.f, 200.f));
    sf::RectangleShape shape2(sf::Vector2f(200.f, 200.f));
	sf::RectangleShape base(sf::Vector2f(900, 50));
	base.setPosition(0, 800);
    sf::RectangleShape base2(sf::Vector2f(900, 500));
    base2.setPosition(0, 500);
    sf::Texture bas;
    bas.loadFromFile("assets\\floor.png");
    base2.setTexture(&bas);
    sf::Shader shader2;
    //g.Light(base2, shader2);
	CollisionSide shape1collisions;
    sf::Texture left;
    left.loadFromFile("assets\\left.png");
    sf::Texture right;
    right.loadFromFile("assets\\right.png");
	shape1collisions.bottom = false;
    
    shape1.setPosition(100.f, 100.f);
    sf::CircleShape shape(50.f);
	shape.setPosition(300, 50);
    sf::Texture bulb;
    bulb.loadFromFile("assets\\bulb.jpg");
    shape.setTexture(&bulb);
    
    sf::Vector2f asada;
    asada.x = shape.getPosition().x + shape.getRadius();
    asada.y = shape.getPosition().y + shape.getRadius();
    //shader3.setUniform("lightPos", asada);
    sf::View view2(sf::Vector2f(350.f, 300.f), sf::Vector2f(500.f, 500.f));
    
    CollisionSide collisions;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        g.enableMovement(shape1);
        //shader2.setUniform("lightPos", sf::Vector2f(shape1.getPosition().x+shape1.getSize().x/2, shape1.getPosition().y - shape1.getSize().y*2));
        g.animation(shape1, &left, &right, &right, &right);
        g.moveView(shape1, view2);
        g.enableMovement(shape);
        sf::Shader s;
        g.Light(shape, s); // Makes a light
        // To make a follow light, pass the shader with the shape, into follow light
        // only draw the surface with shader on which you want the light to follow the player
        g.FollowLight(shape1, shader2); // Makes Follow Light
        window.clear();
        //window.draw(shape1, &shader);
        window.draw(base);
        window.draw(base2, &shader2);
        window.draw(shape1);
        //window.draw(shape, &s);
        window.setView(view2);
        
        
        
        
        window.display();   
    }
    return 0;
}
