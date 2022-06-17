#include "Game.h"
#include <SFML/Graphics.hpp>
	
#include <string>
#include <iostream>
#include <sstream>
Game::Game()
	: window(sf::VideoMode::getDesktopMode(), "Dino Run", sf::Style::Titlebar | sf::Style::Close)
	, gameClock()
	, playerInstance(this)
	, obstacleInstance()
	, flyingObstacleInstance()
	, itemInstance()
	, timeSinceEnemy()
	, font()
	, scoreText()
	, gameOverText()
	, restartButton()
	, isGameOver(false)
{
}

void Game::Run()
{
	SetupGame();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		//Update
		Update();
		//Draw
		Draw();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) && !playerInstance.GetAlive())
		{
			RestartGame();
		}
	}

	//Close the game if escape is pressed
}

void Game::Draw()
{
	window.clear();
	playerInstance.Draw(window);
	obstacleInstance.Draw(window);
	flyingObstacleInstance.Draw(window);
	itemInstance.Draw(window);

	window.draw(scoreText);

	if (!playerInstance.GetAlive())
	{
		window.draw(gameOverText);
		window.draw(restartButton);
	}
	window.display();
}

void Game::Update()
{
	//sf::Time is for storing time precisely.
	//Time passed since last frame.
	sf::Time deltaTime = gameClock.restart();

	playerInstance.Update(deltaTime);
	//Only run this while player is still alive
	if (playerInstance.GetAlive())
	{

		obstacleInstance.Update(deltaTime);
		flyingObstacleInstance.Update(deltaTime);
		itemInstance.Update(deltaTime);
		std::stringstream ss;
		ss << "SCORE: " << playerInstance.GetScore();
		scoreText.setString(ss.str());
	}
	
	if (obstacleInstance.IsColliding(playerInstance) || flyingObstacleInstance.IsColliding(playerInstance))
	{
		playerInstance.SetAlive(false);
	}

	if (itemInstance.IsColliding(playerInstance))
	{
		itemInstance.BoostScore(playerInstance.GetScore());
	}

	//Enemy spawn frequency
	float enemyFrequency = 2.0f;
	timeSinceEnemy += deltaTime;

	if (timeSinceEnemy.asSeconds() >= enemyFrequency)
	{
		SpawnEnemy();
		timeSinceEnemy = sf::Time();
	}
}

bool Game::IsGameOver()
{
	return isGameOver;
}

void Game::SetupGame()
{
	sf::Vector2f screenSize(window.getSize());
	sf::RectangleShape playerRectDisplay;
	//Put our player in the centre of the screen vertically and near the left side.
	playerInstance.SetPosition(sf::Vector2f(100, screenSize.y / 2 - 50));
	obstacleInstance.SetPosition(sf::Vector2f(screenSize.x, screenSize.y / 2 - 50));
	flyingObstacleInstance.SetPosition(sf::Vector2f(2000, 300));
	itemInstance.SetPosition(sf::Vector2f(screenSize.x + 300.0f, screenSize.y / 2));
	font.loadFromFile("Assets/Graphics/enter-command.ttf");

	//Restart Button
	restartButtonTexture.loadFromFile("Assets/Graphics/button-retry.png");
	restartButton.setTexture(restartButtonTexture);
	restartButton.setPosition(screenSize.x / 2 - 60, screenSize.y / 2 + 60);

	//Score Text
	scoreText.setFont(font);
	scoreText.setString("Score: " + playerInstance.GetScore());
	scoreText.setPosition(screenSize.x - 300, 100);

	//Game Over Text
	gameOverText.setFont(font);
	gameOverText.setString("GAME OVER");
	gameOverText.setPosition(screenSize.x / 2 - 200, screenSize.y / 2 - 60);
	gameOverText.setCharacterSize(100);

	//Music
	gameMusic.openFromFile("Assets/Sounds/music.ogg");
	gameMusic.setVolume(30.0f);
	gameMusic.play();
}

void Game::SpawnEnemy()
{
	//Special pointer EVERY class has called "this"

	int enemyChoice = rand() % 100;
	int chaseEnemyChance = 50;
}

void Game::RestartGame()
{
	playerInstance.ResetScore();
	sf::Vector2f screenSize(window.getSize());
	playerInstance.SetPosition(sf::Vector2f(100, screenSize.y / 2 - 50));
	obstacleInstance.SetPosition(sf::Vector2f(screenSize.x, screenSize.y / 2 - 50));
	itemInstance.SetPosition(sf::Vector2f(screenSize.x, screenSize.y / 2 - 50));
	flyingObstacleInstance.SetPosition(sf::Vector2f(2000, 300));
	playerInstance.SetAlive(true);
}


sf::Vector2f Game::GetScreenSize()
{
	return (sf::Vector2f)window.getSize();
}
