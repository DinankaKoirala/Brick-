#include <SFML/Graphics.hpp>
#include <iostream>
#include<cmath>
#include<vector>

#include "Header/paddle.h"
#include "Header/ball.h"
#include "Header/brick.h"
#include "Header/deathscreen.h"

enum class GameState {
    Playing,
    Dead
};

int main() {
	unsigned int width = 1280;
	unsigned int height = 720;
	sf::RenderWindow window(sf::VideoMode({ width, height }), "Brick Breaker");
	window.setFramerateLimit(60);

	GameState currrentstate = GameState::Playing;

	//Create game objects
	Paddle paddle(static_cast<float>(width), static_cast<float>(height));
	Ball ball(static_cast<float>(width), static_cast<float>(height));
	DeathScreen deathscreen(static_cast<float>(width), static_cast<float>(height));

	//Creates Brick
	std::vector<Brick> bricks;
	for (int i = 0; i <= width/100; ++i) {
		for (int j = 0; j <= (height/2.f)/80; ++j) {
			bricks.emplace_back(sf::Vector2f{
				 i * 100.f,
				j * 40.f
				});
		}
	}

	//Game Loop
	while (window.isOpen()) {

		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
			else if (const auto* keypress = event->getIf<sf::Event::KeyPressed>()) {
				if (keypress->scancode == sf::Keyboard::Scancode::Escape) {
					window.close();
				}
			}
		}

		if(currrentstate == GameState::Playing){
		paddle.update();
		ball.update(static_cast<float>(width), static_cast<float>(height));

		if (ball.getShape().getGlobalBounds().findIntersection(paddle.getShape().getGlobalBounds())) {
			ball.getVelocity().y = -std::abs(ball.getVelocity().y);
		}

		sf::Vector2f ballpos = ball.getShape().getPosition();
		float ballrad = ball.getShape().getRadius();

		if (ballpos.y + ballrad >= height) {
		currrentstate = GameState::Dead;

	}


		for (Brick& brick : bricks) {
			if (!brick.isdestroyed() && brick.getshape().getGlobalBounds().findIntersection(ball.getShape().getGlobalBounds())) {
				brick.destroy();
				ball.getVelocity().y = -ball.getVelocity().y;
				break;
			}
		}
		
}
if(currrentstate == GameState::Dead){
	DeathScreenResult result = deathscreen.getInput(window);
	if(result == DeathScreenResult::Restart){
		ball.reset(static_cast<float>(width), static_cast<float>(height));
    paddle.reset(static_cast<float>(width), static_cast<float>(height));
    bricks.clear();
    for (int i = 0; i <= width/100; ++i) {
        for (int j = 0; j <= (height/2.f)/80; ++j) {
            bricks.emplace_back(sf::Vector2f{
                i * 100.f,
                j * 40.f
            });
        }
    }
    currrentstate = GameState::Playing;

	}
	else if (result == DeathScreenResult::Exit){
		window.close();
	}
}

		


		// Render
		window.clear(sf::Color(0x87CEEFFF));

		for (Brick& brick : bricks) {
			brick.draw(window);
		}
		paddle.draw(window);
		ball.draw(window);
		if(currrentstate == GameState::Dead){
			deathscreen.draw(window);
		}
		//Draw 
		window.display();

	}

}