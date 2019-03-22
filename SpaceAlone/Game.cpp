#include "Game.hpp"

Game::Game(){}

Game::~Game(){}

/*
* Method that initiates the game loop
*/
int Game::init()
{
	// creates a window
	sf::RenderWindow window(sf::VideoMode(1024, 720), "Space Alone", sf::Style::Close | sf::Style::Resize);
	//sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 720.0f));

	// creates background sprite
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("C:/Users/Wallef/Pictures/background.jpg");
	sf::Sprite background;
	background.setTexture(backgroundTexture);
	background.setPosition(-50.0f, 0.0f);

	//sets texture for player and instatiates a new player
	sf::Texture playerTexture;
	playerTexture.loadFromFile("C:/Users/Wallef/Pictures/robot.png");
	Player player(&playerTexture, sf::Vector2u(3, 2), 0.3f, 100.0f, 100.0f);

	// sets texture for platform and instatiates a new platform
	sf::Texture platformTexture;
	platformTexture.loadFromFile("C:/Users/Wallef/Pictures/platform.png");
	Platform platform(&platformTexture, sf::Vector2f(1100.0f, 220.0f), sf::Vector2f(510.0f, 700.0f));

	// sets texture for platform and instatiates a new platform
	sf::Texture boxTexture;
	boxTexture.loadFromFile("C:/Users/Wallef/Pictures/box.jpg");
	Platform box(&boxTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(600.0f, 563.0f));

	// initiates delta time
	float deltaTime = 0.0f;
	sf::Clock clock;

	// Game loop
	while (window.isOpen())
	{
		// gets the time difference between frames as a float
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

		// checks for collision between the ground and the player
		if (platform.getCollider().checkCollision(playerCollider, direction, 1.0f));
		{
			// applies collision to player
			player.onCollision(direction);
		}

		// checks for collision between the box and the player
		if (box.getCollider().checkCollision(playerCollider, direction, 1.0f));
		{
			player.onCollision(direction);
		}

		// clears previous frame
		window.clear();

		// draws all the elements on the window
		window.draw(background);
		//window.setView(view);
		player.draw(window);
		platform.draw(window);
		box.draw(window);

		//displays the new frame
		window.display();
	}
	return EXIT_SUCCESS;
}

void loop() {

}