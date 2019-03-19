#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "database.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 720), "Space Alone", sf::Style::Close | sf::Style::Resize);
	//sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 720.0f));

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("C:/Users/Wallef/Pictures/background.jpg");
	sf::Sprite background;
	background.setTexture(backgroundTexture);
	background.setPosition(-50.0f, 0.0f);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("C:/Users/Wallef/Pictures/robot.png");

	Player player(&playerTexture, sf::Vector2u(3, 2), 0.3f, 100.0f, 100.0f);

	sf::Texture enemyTexture;
	enemyTexture.loadFromFile("C:/Users/Wallef/Pictures/platform.png");
	Enemy enemy(&enemyTexture, sf::Vector2f(1100.0f, 220.0f), sf::Vector2f(510.0f, 700.0f));

	sf::Texture boxTexture;
	boxTexture.loadFromFile("C:/Users/Wallef/Pictures/box.jpg");
	Enemy box(&boxTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(600.0f, 563.0f));

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

		//view.setCenter(player.getPosition());
		player.update(deltaTime);

		sf::Vector2f direction;
		Collider playerCollider = player.getCollider();
		Collider enemyCollider = enemy.getCollider();

		if (enemy.getCollider().checkCollision(playerCollider, direction, 1.0f));
		{
			player.onCollision(direction);
		}

		if (box.getCollider().checkCollision(playerCollider, direction, 1.0f));
		{
			player.onCollision(direction);
		}

		box.getCollider().checkCollision(enemyCollider, direction, 1.0f);

		window.clear();
		window.draw(background);
		//window.setView(view);
		player.draw(window);
		enemy.draw(window);
		box.draw(window);
		window.display();
	}
	return EXIT_SUCCESS;
}
