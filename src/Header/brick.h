#pragma once
#include<SFML/Graphics.hpp>


class Brick{

private:
	sf::RectangleShape BrickShape;
	bool destroyed;

public:
	Brick(sf::Vector2f position);
	void draw(sf::RenderWindow& window);
	void destroy();
	void reset(float width, float height);

	bool isdestroyed() const;
	sf::RectangleShape& getshape();

};
