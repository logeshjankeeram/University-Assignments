#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Maze Runner", sf::Style::Close);
	window.setFramerateLimit(60);

	Game game(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		game.update();

		window.clear(sf::Color::Black);

		game.draw();

		window.display();
	}

	return 0;
}