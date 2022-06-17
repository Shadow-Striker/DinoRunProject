#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GameObject.h"
#include "Obstacle.h"
#include "Game.h"

int main()
{
	//Seeding RNG
	srand(time(NULL));
	Game ourGame;
	ourGame.Run();
	return 0;
}