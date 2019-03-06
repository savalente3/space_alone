#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 720), "Space Alone", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 720.0f));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("C:/Users/Wallef/Pictures/tux.png");

	Player player(&playerTexture, sf::Vector2u(3, 2), 0.3f, 100.0f);

	Enemy enemy(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(500.0f, 200.0f));

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event event;

		// handle all events
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				std::cout << event.size.width << " " << event.size.height << std::endl;
				break;
			}
		}

		view.setCenter(player.getPosition());
		player.update(deltaTime);

		Collider playerCollider = player.getCollider();
		enemy.getCollider().checkCollision(playerCollider, 0.5f);

		window.clear(sf::Color(150, 150, 150));
		window.setView(view);
		player.draw(window);
		enemy.draw(window);
		window.display();
	}
	return EXIT_SUCCESS;
}
