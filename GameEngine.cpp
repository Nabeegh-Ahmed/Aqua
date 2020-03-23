#include "GameEngine.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
#include<string>
using namespace std;

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
	if (pos2.y + size2.y > pos1.y && pos2.x < pos1.x + size1.x && pos2.x + size2.x > pos1.x && pos2.y < pos1.y) {
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
void GameEngine::Gravity(sf::RectangleShape &fallingobject, sf::RectangleShape& base) {
	CollisionSide _base = this->areColliding(fallingobject, base);
	static double velocity = 0.01;
	double acceleration = 0.0010;
	if (_base.top == false) {
		sf::Vector2f objectposition = fallingobject.getPosition();
		fallingobject.move(0.0f, velocity);
		if (velocity < 20) {
			velocity += acceleration;
		}
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			fallingobject.move(0.f, -1.f);
		}
		
		velocity = 0.001;
	}
	if (_base.bottom) {
		fallingobject.move(0.f, 3.f);
	}
}
void GameEngine::Gravity(sf::CircleShape& fallingobject, sf::RectangleShape& base) {
	CollisionSide _base = this->areColliding(fallingobject, base);
	static double velocity = 0.1;
	double acceleration = 0.010;
	if (_base.top == false) {
		sf::Vector2f objectposition = fallingobject.getPosition();
		fallingobject.move(0.0f, velocity);
		if (velocity < 20) {
			velocity += acceleration;
		}
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			fallingobject.move(0.f, -1.f);
		}
		velocity = 0.1;
	}
}
void GameEngine::animation(sf::RectangleShape& shape, sf::Texture* left, sf::Texture* right, sf::Texture* up, sf::Texture* down) {
	static int xvelocity = 0.1;
	static int yvelocity = 0.1;
	int lastyvelocity = yvelocity;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		shape.setTexture(left);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		shape.setTexture(right);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		// Up sprite
		yvelocity++;
	}
	else {
		yvelocity--;
	}
	if (lastyvelocity > yvelocity) {
		// downsprite
	}
}
void GameEngine::Gravity(sf::RectangleShape& fallingobject, CollisionSide isfalling) {
	static double velocity = 0.001;
	double acceleration = 0.000010;
	if (isfalling.top == false) {
		sf::Vector2f objectposition = fallingobject.getPosition();
		fallingobject.move(0.0f, velocity);
		if (velocity < 20) {
			velocity += acceleration;
		}
	}
	else {
		velocity = 1.0;
	}
}
void GameEngine::Gravity(sf::CircleShape& fallingobject, CollisionSide isfalling) {
	static double velocity = 0.001;
	double acceleration = 0.000010;
	if (isfalling.top == false) {
		sf::Vector2f objectposition = fallingobject.getPosition();
		fallingobject.move(0.0f, velocity);
		if (velocity < 20) {
			velocity += acceleration;
		}
	}
	else {
		velocity = 1.0;
	}
}
void GameEngine::enableMovement(sf::RectangleShape& shape) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		shape.move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		shape.move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		shape.move(0.f, -3.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		shape.move(0.f, 1.f);
	}
}
void GameEngine::enableMovement(sf::CircleShape& shape) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		shape.move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		shape.move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		shape.move(0.f, -3.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		shape.move(0.f, 1.f);
	}
}
void GameEngine::moveView(sf::RectangleShape& shape, sf::View& view) {
	sf::Vector2f pos = shape.getPosition();
	view.setSize(sf::Vector2f(shape.getSize().x * 5, shape.getSize().x * 5));
	view.setCenter(sf::Vector2f(pos.x+shape.getSize().x/2, pos.y));
}