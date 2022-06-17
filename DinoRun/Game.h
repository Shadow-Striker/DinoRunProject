#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Obstacle.h"
#include "FlyingObstacle.h"
#include "Item.h"

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
	void RestartGame();

	sf::RenderWindow window;
	sf::Clock gameClock;
	Player playerInstance;
	Obstacle obstacleInstance;
	FlyingObstacle flyingObstacleInstance;
	Item itemInstance;
	sf::Time timeSinceEnemy;
	sf::Font font;
	sf::Text scoreText;
	sf::Text gameOverText;
	sf::Sprite restartButton;
	sf::Texture restartButtonTexture;
	sf::Music gameMusic;
	bool isGameOver;


	sf::Vector2f GetScreenSize();

};


