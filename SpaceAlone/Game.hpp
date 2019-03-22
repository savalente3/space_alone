#ifndef Game_h
#define Game_h

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Platform.hpp"
#include "Collider.hpp"

class Game
{
public:
	Game();
	~Game();

	int init();
};

#endif
