#include "Header/paddle.h"

Paddle::Paddle(float width, float height) {
	PaddleShape.setSize({ 100.f,20.f });
	PaddleShape.setOrigin(PaddleShape.getSize() / 2.f);
	PaddleShape.setPosition({ width / 2.f, (height - 10) * 1.f });
	speed = 10.f;
	PaddleShape.setFillColor(sf::Color::Red);
}


void Paddle::update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
		PaddleShape.move({ -speed,0.f });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {
		PaddleShape.move({ speed,0.f });
	}
}

sf::RectangleShape& Paddle::getShape() {
	return PaddleShape;
}

void Paddle::draw(sf::RenderWindow& window) {
	window.draw(PaddleShape);
}
void Paddle::reset(float width, float height) {
    PaddleShape.setPosition({width / 2.f, (height - 10) * 1.f});
}