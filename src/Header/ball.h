#pragma once
#include<SFML/Graphics.hpp>

class Ball{

private:
	sf::CircleShape BallShape;
	sf::Vector2f velocity;

public:
	Ball(float width, float height);

	void update(float width, float height);
	void draw(sf::RenderWindow& window);

	sf::CircleShape& getShape();
	sf::Vector2f& getVelocity();


};