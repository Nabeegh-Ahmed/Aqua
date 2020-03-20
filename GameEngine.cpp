#include "GameEngine.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<math.h>

bool GameEngine::MouseClick(sf::RectangleShape target, sf::Event::MouseButtonEvent mouse) {
	sf::Vector2f targetPos = target.getPosition();
	sf::Vector2f size = target.getSize();
	if (mouse.x >= targetPos.x && mouse.x <= targetPos.x + size.x && mouse.y >= targetPos.y && mouse.y <= targetPos.y + size.y)
		return true;
	else
		return false;
}
bool GameEngine::MouseClick(sf::CircleShape target, sf::Event::MouseButtonEvent mouse) {
	sf::Vector2f targetPos = target.getPosition();
	float size = target.getRadius();
	sf::Vector2f origin = target.getOrigin();
	origin.x += size;
	origin.y += size;
	double dist = pow((pow(mouse.y - origin.y, 2) + pow(mouse.x - origin.x, 2)), 0.5);
	if (mouse.x >= targetPos.x && mouse.x <= targetPos.x + 2 * size && mouse.y >= targetPos.y && mouse.y <= targetPos.y + 2 * size) {
		if (dist < size) {
			return true;
		}
		else {
			return false;
		}
	} else {
		return false;
	}
}
CollisionSide GameEngine::areColliding(sf::RectangleShape r1, sf::RectangleShape r2) {
	// r1 is moving and check collision with r2
	CollisionSide collisions;
	collisions.bottom = false;
	collisions.top = false;
	collisions.left = false;
	collisions.right = false;
	sf::Vector2f pos1 = r1.getPosition();
	sf::Vector2f size1 = r1.getSize();
	sf::Vector2f pos2 = r2.getPosition();
	sf::Vector2f size2 = r2.getSize();
	if (pos1.x + size1.x > pos2.x && pos1.y < pos2.y + size2.y && pos1.y+size1.y > pos2.y && pos1.x < pos2.x) {
		collisions.left = true;
	}
	if (pos1.x + size1.x > pos2.x&& pos1.y < pos2.y + size2.y && pos1.y + size1.y > pos2.y && pos1.x == pos2.x+size2.y) {
		collisions.right = true;
	}
	if (pos1.y + size1.y > pos2.y && pos1.x < pos2.x + size2.x && pos1.x + size1.x > pos2.x && pos1.y < pos2.y) {
		collisions.top = true;
	}
	if (pos1.y + size1.y > pos2.y && pos1.x < pos2.x + size2.x && pos1.x + size1.x > pos2.x && pos1.y == pos2.y + size2.x) {
		collisions.bottom = true;
	}

	return collisions;
}
CollisionSide GameEngine::areColliding(sf::CircleShape r1, sf::RectangleShape r2) {
	
	return c;
}