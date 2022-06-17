#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Obstacle.h"

class Game
{
public:

	Game();

	void Run();
	void Draw();
	void Update();

private:
	void SetupGame();
	void SpawnEnemy();

	sf::RenderWindow window;
	sf::Clock gameClock;
	Player playerInstance;
	Obstacle obstacleInstance;
	sf::Time timeSinceEnemy;
	sf::Font font;
	sf::Text scoreText;


	sf::Vector2f GetScreenSize();

};


