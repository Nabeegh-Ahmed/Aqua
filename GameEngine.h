#pragma once
#include<SFML/Graphics.hpp>

struct CollisionSide {
	bool top, bottom, left, right;
};

class GameEngine {
public:
	bool MouseClick(sf::RectangleShape, sf::Event::MouseButtonEvent);
	bool MouseClick(sf::CircleShape, sf::Event::MouseButtonEvent);
	CollisionSide areColliding(sf::RectangleShape, sf::RectangleShape referencePoint);
	CollisionSide areColliding(sf::CircleShape, sf::RectangleShape);
	//CollisionSide areColliding(sf::CircleShape, sf::CircleShape);
};

