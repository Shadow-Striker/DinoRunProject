#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Obstacle.h"
#include "FlyingObstacle.h"

class Game
{
public:

	Game();

	void Run();
	void Draw();
	void Update();
	bool IsGameOver();

private:
	void SetupGame();
	void SpawnEnemy();

	sf::RenderWindow window;
	sf::Clock gameClock;
	Player playerInstance;
	Obstacle obstacleInstance;
	FlyingObstacle flyingObstacleInstance;
	sf::Time timeSinceEnemy;
	sf::Font font;
	sf::Text scoreText;
	sf::Text gameOverText;
	sf::Sprite restartButton;
	sf::Texture restartButtonTexture;
	bool isGameOver;


	sf::Vector2f GetScreenSize();

};


