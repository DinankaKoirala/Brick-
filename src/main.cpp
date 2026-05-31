#include <SFML/Graphics.hpp>
#include <iostream>
int main() {
	unsigned int width = 1280;
	unsigned int height = 720;
sf::RenderWindow window(sf::VideoMode({ width, height }), "Brick Breaker");
window.setFramerateLimit(60);

sf::RectangleShape paddle({ 100.f,20.f });
paddle.setOrigin(paddle.getSize() / 2.f);
paddle.setPosition({ width / 2.f, (height-10)*1.f});


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
		paddle.move({ -1.f,0.f });


		// Render
		window.clear(sf::Color(0x87CEEFFF));


		//Draw 
		window.draw(paddle);
		window.display();

	}

}