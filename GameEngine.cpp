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
	CollisionSide c;
	c.left = false;
	c.right = false;
	c.bottom = false;
	c.top = false;
	sf::Vector2f CirclePosition = r1.getPosition();
	double CircleSize = r1.getRadius();
	CirclePosition.x += CircleSize;
	CirclePosition.y += CircleSize;
	sf::Vector2f RectanglePosition = r2.getPosition();
	sf::Vector2f RectangleSize = r2.getSize();
	sf::Vector2f Collisioncoords = CirclePosition;
	Collisioncoords.x = CirclePosition.x + CircleSize;
	Collisioncoords.y = CirclePosition.y;
	for (double angle = 0.0,incrementer=0.0; angle <= 90; angle += 3,incrementer+= 0.03333333) {
		if ((((Collisioncoords.x - CircleSize * incrementer) >= (RectanglePosition.x)) && ((Collisioncoords.x - CircleSize * incrementer) <= (RectanglePosition.x + 3.5))) && (((Collisioncoords.y - CircleSize * incrementer) >= (RectanglePosition.y)) && ((Collisioncoords.y - CircleSize * incrementer) <= (RectanglePosition.y + RectangleSize.y)))) {
			c.left = true;
		}
		if ((((Collisioncoords.x - CircleSize * incrementer) >= (RectanglePosition.x)) && ((Collisioncoords.x - CircleSize * incrementer) <= (RectanglePosition.x + RectangleSize.x))) && (((Collisioncoords.y - CircleSize * incrementer) >= (RectanglePosition.y+RectangleSize.y-3.5)) && ((Collisioncoords.y - CircleSize * incrementer) <= (RectanglePosition.y + RectangleSize.y)))) {
			c.bottom=true;
		}
	}
	Collisioncoords.x = CirclePosition.x;
	Collisioncoords.y = CirclePosition.y - CircleSize;
	for (double angle = 90, incrementer = 0.0; angle <= 180; angle += 3, incrementer += 0.03333333) {
		if ((((Collisioncoords.x - CircleSize * incrementer) >= (RectanglePosition.x+RectangleSize.x-3.5)) && ((Collisioncoords.x - CircleSize * incrementer) <= (RectanglePosition.x + RectangleSize.x))) && (((Collisioncoords.y + CircleSize * incrementer) >= (RectanglePosition.y)) && ((Collisioncoords.y + CircleSize * incrementer) <= (RectanglePosition.y + RectangleSize.y)))) {
			c.right = true;
		}
		if ((((Collisioncoords.x - CircleSize * incrementer) >= (RectanglePosition.x)) && ((Collisioncoords.x - CircleSize * incrementer) <= (RectanglePosition.x + RectangleSize.x))) && (((Collisioncoords.y + CircleSize * incrementer) >= (RectanglePosition.y + RectangleSize.y - 3.5)) && ((Collisioncoords.y + CircleSize * incrementer) <= (RectanglePosition.y + RectangleSize.y)))) {
			c.bottom = true;
		}
	}
	Collisioncoords.x = CirclePosition.x-CircleSize;
	Collisioncoords.y = CirclePosition.y;
	for (double angle = 180,incrementer=0.0; angle <= 270; angle += 3,incrementer+= 0.03333333) {
		if ((((Collisioncoords.x + CircleSize * incrementer) >= (RectanglePosition.x )) && ((Collisioncoords.x + CircleSize * incrementer) <= (RectanglePosition.x + RectangleSize.x))) && (((Collisioncoords.y + CircleSize * incrementer) >= (RectanglePosition.y)) && ((Collisioncoords.y + CircleSize * incrementer) <= (RectanglePosition.y +3.5)))) {
			c.top = true;
		}
		if ((((Collisioncoords.x + CircleSize * incrementer) >= (RectanglePosition.x + RectangleSize.x - 3.5)) && ((Collisioncoords.x + CircleSize * incrementer) <= (RectanglePosition.x + RectangleSize.x))) && (((Collisioncoords.y + CircleSize * incrementer) >= (RectanglePosition.y )) && ((Collisioncoords.y + CircleSize * incrementer) <= (RectanglePosition.y + RectangleSize.y)))) {
			c.right = true;
		}
	}
	Collisioncoords.x = CirclePosition.x;
	Collisioncoords.y = CirclePosition.y+CircleSize;
	for (double angle = 270,incrementer=0.0; angle <= 360; angle += 3,incrementer+= 0.03333333) {
		if ((((Collisioncoords.x + CircleSize * incrementer) >= (RectanglePosition.x)) && ((Collisioncoords.x + CircleSize * incrementer) <= (RectanglePosition.x + RectangleSize.x))) && (((Collisioncoords.y - CircleSize * incrementer) >= (RectanglePosition.y)) && ((Collisioncoords.y - CircleSize * incrementer) <= (RectanglePosition.y + 3.5)))) {
			c.top = true;
		}
		if ((((Collisioncoords.x + CircleSize * incrementer) >= (RectanglePosition.x)) && ((Collisioncoords.x + CircleSize * incrementer) <= (RectanglePosition.x + 3.5))) && (((Collisioncoords.y - CircleSize * incrementer) >= (RectanglePosition.y)) && ((Collisioncoords.y - CircleSize * incrementer) <= (RectanglePosition.y + RectangleSize.y)))) {
			c.left = true;
		}
	}
	return c;
	
}