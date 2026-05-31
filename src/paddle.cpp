#include "Header/paddle.h"
#include<iostream>

padde::paddle(float Width, float Height) {
	PaddleShape.setsize({ 100.f,20.f });
	PaddleShape.setOrigin(PaddleShape.getSize() / 2.f);
	PaddleShape.setPosition({ width / 2.f, (height - 10) * 1.f });
}

paddle.setfillColor(sf::Color(0xFF0000FF));

void paddle::update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
		paddle.move({ -speed,0.f });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {
		paddle.move({ speed,0.f });
	}
}

sf::RectangleShape& paddlle::getShape() {
	return PaddleShape;
}

void paddle::draw(sf::RenderWindow& window) {
	window.draw(PaddleShape);
}