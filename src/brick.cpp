#include"Header/brick.h"
#include<SFML/Graphics.hpp>
#include<iostream>

Brick::Brick(sf::Vector2f position) {
	BrickShape.setSize({80.f , 30.f});
	BrickShape.setPosition(position);
	BrickShape.setFillColor(sf::Color(0xFFA500FF));

	destroyed = false;
}
void Brick::draw(sf::RenderWindow& window) {
	if (!destroyed) {
		window.draw(BrickShape);
	}
}
void Brick::destroy() {
	destroyed = true;
}
bool Brick::isdestroyed() const {
	return destroyed;
}
sf::RectangleShape& Brick::getshape() {
	return BrickShape;
}
