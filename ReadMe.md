<h2>How to use?</h2>
<ol>
<li>Clone this repo.
<li>Add #include "GameEngine.h" in your file.
</ol>

<h1> Usage </h1>
From now on you will see each function provided with vital information.

<h2>Graphics and Physics</h2>
<i>Make a GPEngine object in your main file. We will be using an object called Engine. </i>

<li>MouseClick(sf::RectangleShape, sf::Event::MouseButtonEvent);</li>

Return type: Bool.
Function: Return True if an SFML Rectangle Shape is clicked on.
Example:
 if (Engine.MouseClick(shape, event.mouseButton)) {
std::cout << "clicked";
 }

=> Always pass event.mouseButton as the second argument. 

<li>MouseClick(sf::CircleShape, sf::Event::MouseButtonEvent);

Return type: Bool.
Function: Return True if an SFML Rectangle Shape is clicked on.
Example:
 if (Engine.MouseClick(shape, event.mouseButton)) {
std::cout << "clicked";
 }

=> Always pass event.mouseButton as the second argument. 

<i>CollisionSide is a struct with four boolean variables. It is already defined in the GameEngine. Just use CollisionSide (name); to make an instance.</i>

<li>CollisionSide areColliding(sf::RectangleShape toCheck, sf::RectangleShape referencePoint);

Return type: CollisionSide.
Function: CollisionSide is a struct that has four booleans. The booleans are set to true if a rectangle shape(passed as the first argument) is touching with any of the four sides of the rectangle shape referencePoint(passed as the second argument).
Example:
CollisionSide collisions = Engine.areColliding(shape1, shape2);
if(collisions.left)
	std::cout<<” Shape1 is touching the left side of the shape2”;
if(collisions.right)
	std::cout<<” Shape1 is touching the right side of the shape2”;
if(collisions.top)
	std::cout<<” Shape1 is touching the top side of the shape2”;
if(collisions.bottom)
	std::cout<<” Shape1 is touching the bottom side of the shape2”;

<li>CollisionSide areColliding(sf::CircleShape toCheck, sf::RectangleShape referencePoint);

Return type: CollisionSide.
Function: CollisionSide is a struct that has four booleans. The booleans are set to true if a circle shape(passed as the first argument) is touching with any of the four sides of the rectangle shape referencePoint(passed as the second argument).
Example:
CollisionSide collisions = Engine.areColliding(shape1, shape2);
if(collisions.left)
	std::cout<<” Shape1 is touching the left side of the shape2”;
if(collisions.right)
	std::cout<<” Shape1 is touching the right side of the shape2”;
if(collisions.top)
	std::cout<<” Shape1 is touching the top side of the shape2”;
if(collisions.bottom)
	std::cout<<” Shape1 is touching the bottom side of the shape2”;

<li>void Gravity(sf::RectangleShape &fallingobject, sf::RectangleShape& base);

Return type: Void.
Function: Apply Gravity to a rectangle shape. base is used as ground. When the fallingobject touches the base it will stop falling.
Example: Engine.Gravity(shape1, base);

<li>void Gravity(sf::CircleShape &fallingobject, sf::RectangleShape& base);

Return type: Void.
Function: Apply Gravity to a circle shape. base is used as ground. When the fallingobject touches the base it will stop falling.
Example: Engine.Gravity(shape1, base);

<li>void Gravity(sf::RectangleShape& fallingobject, CollisionSide baseCollisionObject);
Return type: Void.
Function: Apply Gravity to a Rectangle shape. baseCollisionObject can be obtained by using the areColliding(shapeToApplyGravityTo, Ground); This function works best if you have more than one surface you want to make ground.
Example: 

collision Side cs = Engine.areColliding(shape1, base);
Engine.Gravity(shape1, cs);

<li>void Gravity(sf::CircleShape& fallingobject, CollisionSide baseCollisionObject);

Return type: Void.
Function: Apply Gravity to a circle shape. baseCollisionObject can be obtained by using the areColliding(shapeToApplyGravityTo, Ground); This function works best if you have more than one surface you want to make ground.
Example: 

collision Side cs = Engine.areColliding(shape1, base);
Engine.Gravity(shape1, cs);

<li>void enableMovement(sf::RectangleShape& shape);

Return type: Void.
Function: Apply movement to a Rectangle Shape
Example: Engine.enableMovement(shape1);
=> The speed is by default set to 1px per key pressed, you can change it in the code.

<li>void enableMovement(sf::CircleShape& shape);

Return type: Void.
Function: Apply movement to a Circle Shape
Example: Engine.enableMovement(shape1);
=> The speed is by default set to 1px per key pressed, you can change it in the code.

<li>void animation(sf::RectangleShape& shape, sf::Texture* left, sf::Texture* right, sf::Texture* up, sf::Texture* down);

Return type: Void.
Function: Change textures of a shape with respect to the movement.
Example: Engine.animation(shape1, &leftTexture, &rightTexture, &upTexture, &DownTexture);

<li>void GameEngine::moveView(sf::RectangleShape& shape, sf::View& view);
Return type: Void.
Function: Move an SFML view with respect to a shape. An SFML view is essentially a 2D camera. With this function you can keep the camera in one shape all the time. 
Example: Engine.moveView(shape1, view);

<li>void GameEngine::ShapeRepeater(sf::RectangleShape shapeInFocus,sf::RectangleShape &ShapeToRepeat, sf::RenderWindow & screen, sf::Vector2f& StartingPos, float DistanceBetweenShape);

Return type: Void.
Function: Draw endless shapes as a shape moves. Consider something like pacman, where there are endless poles generated, this function works similar to that. shapeInFocus is the shape with respect to which ShapeToRepeat will be generated. Screen is the object you use to create a window in SFML, pass that here. StartingPos tells from which height the shapes will start drawing. DistanceBetweenShape is how much distance you want in the shapes.

<li>void Light(sf::RectangleShape shape, sf::Shader& s);
Return type: Void.
Function: origin of a shape is lit.
sf::Shader s;
Engine.Light(shape1, s);
Window.draw(shape1, s);

<li>void FollowLight(sf::RectangleShape shape, sf::Shader& s);
Return type: Void.
Function: Makes the background dark and a light follows the passed rectangle shape.
Example:
sf::Shader s;
Engine.FollowLight(shape1, s);
// When drawing shapes
window.draw(the-shape-on-which-the-light-will-follow-shape1, &s);

<h2>UI Engine</h2>
We have also included a simple UI engine to help you make menus easily.

<li>uiOptions simpleUI(std::string optionNames[4], sf::RenderWindow& window, sf::Event::MouseButtonEvent);
ReturnType: uiOptions, a struct with 4 booleans.
Function: Makes a fully functioning UI with 4 options, return if one of the options is clicked. Not recommended to use if window size is under 500x500.
=> Always pass event.mouseButton as the third argument.
Example: 
UIEngine ui;
String options[4] = {“Play”, “Options”, “Credits”, “Exit”};
uiOptions selected = ui.simpleUI(options, window, event.mouseButton);
