#pragma once
#include<SFML/Graphics.hpp>
#include<string>
struct CollisionSide {
	bool top, bottom, left, right;
};


class GameEngine {
public:
	bool MouseClick(sf::RectangleShape, sf::Event::MouseButtonEvent);
	bool MouseClick(sf::CircleShape, sf::Event::MouseButtonEvent);
	CollisionSide areColliding(sf::RectangleShape toCheck, sf::RectangleShape referencePoint);
	CollisionSide areColliding(sf::CircleShape toCheck, sf::RectangleShape);
	void Gravity(sf::RectangleShape &fallingobject, sf::RectangleShape& base);
	void Gravity(sf::CircleShape& fallingobject, sf::RectangleShape& base);
	void animation(sf::RectangleShape&, sf::Texture* leftTexture, sf::Texture* rightTexture, sf::Texture* upTexture, sf::Texture* normalTexture);
	void Gravity(sf::RectangleShape& fallingobject, CollisionSide baseCollisionObject);
	void Gravity(sf::CircleShape& fallingobject, CollisionSide baseCollisionObject);
	void enableMovement(sf::RectangleShape& shape);
	void enableMovement(sf::CircleShape& shape);
	void moveView(sf::RectangleShape&, sf::View&);
	//CollisionSide areColliding(sf::CircleShape, sf::CircleShape);
};

