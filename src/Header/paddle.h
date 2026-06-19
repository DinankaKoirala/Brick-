#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Paddle{

private:
	sf::RectangleShape PaddleShape;
	float speed;

public:
	Paddle(float Width, float Height);

	void update();
	void draw(sf::RenderWindow& window);
	void reset(float width, float height);

	sf::RectangleShape& getShape();

};