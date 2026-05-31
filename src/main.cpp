#include <SFML/Graphics.hpp>
#include <iostream>
int main() {
	unsigned int width = 1280;
	unsigned int height = 720;
sf::RenderWindow window(sf::VideoMode({ width, height }), "Brick Breaker");
window.setFramerateLimit(60);

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


		// Render
		window.clear(sf::Color(0x87CEEFFF));


		//Draw 
		window.display();

	}

}