#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class paddle{

private:
	sf::RectangleShape PaddleShape;
	float speed;

public:
	paddle(float Width, float Height);

	void update();
	void draw(sf::RenderWindow& window);

	sf::RectangleShape& getShape();

};