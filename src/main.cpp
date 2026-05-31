#include <SFML/Graphics.hpp>
#include <iostream>
#include<cmath>

#include "Header/paddle.h"
#include "Header/ball.h"

int main() {
	unsigned int width = 1280;
	unsigned int height = 720;
sf::RenderWindow window(sf::VideoMode({ width, height }), "Brick Breaker");
window.setFramerateLimit(60);

//Create game objects
Paddle paddle(static_cast<float>(width), static_cast<float>(height));
Ball ball(static_cast<float>(width), static_cast<float>(height));

//Game Loop
	while(window.isOpen()){
	
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
			else if (const auto* keypress = event->getIf<sf::Event::KeyPressed>()) {
				if (keypress->scancode == sf::Keyboard::Scancode::Escape){
					window.close();
				}
			}
		}
		
		paddle.update();
		ball.update(static_cast<float>(width), static_cast<float>(height));

		if (ball.getShape().getGlobalBounds().findIntersection(paddle.getShape().getGlobalBounds())) {
			ball.getVelocity().y = -std::abs(ball.getVelocity().y);
		}


		// Render
		window.clear(sf::Color(0x87CEEFFF));

		paddle.draw(window);
		ball.draw(window);
		//Draw 
		window.display();

	}

}