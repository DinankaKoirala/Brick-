#include "Header/ball.h"
#include<iostream>

Ball::Ball(float width, float height) {
	BallShape.setRadius(10.f);
	BallShape.setOrigin(BallShape.getGeometricCenter());
	BallShape.setPosition({ width / 2.f , height / 2.f });
	BallShape.setFillColor(sf::Color::White);
	velocity = { 5.f,5.f };
}
void Ball::update(float width, float height) {
	BallShape.move(velocity);

	sf::Vector2f position = BallShape.getPosition();
	float radius = BallShape.getRadius();

	//left wall
	if (position.x - radius <= 0) {
		velocity.x = -velocity.x;
	}
	//right wall
	else if (position.x + radius >= width) {
		velocity.x = -velocity.x;
	}
	//top wall
	if (position.y - radius <= 0) {
		velocity.y = -velocity.y;
	}

}

sf::Vector2f& Ball::getVelocity() {
	return velocity;
}

sf::CircleShape& Ball::getShape() {
	return BallShape;
}

void Ball::draw(sf::RenderWindow& window) {
	window.draw(BallShape);
}

void Ball::reset(float width, float height) {
    BallShape.setPosition({width / 2.f, height / 2.f});
    velocity = {5.f, 5.f};
}