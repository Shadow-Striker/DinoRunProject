#include "Game.h"
#include <SFML/Graphics.hpp>
Game::Game()
	: window(sf::VideoMode::getDesktopMode(), "Dino Run", sf::Style::Titlebar | sf::Style::Close)
	, gameClock()
	, playerInstance(this)
	, obstacleInstance()
	, timeSinceEnemy()
	, font()
	, scoreText()
{
	//New keyword gives us the address to an object
	//AddBullet(new Bullet());
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
	}

	//Close the game if escape is pressed
}

void Game::Draw()
{
	window.clear();
	playerInstance.Draw(window);
	obstacleInstance.Draw(window);
	window.draw(scoreText);
	window.display();
}

void Game::Update()
{
	//sf::Time is for storing time precisely.
	//Time passed since last frame.
	sf::Time deltaTime = gameClock.restart();
	playerInstance.Update(deltaTime);
	obstacleInstance.Update(deltaTime);

	//Enemy spawn frequency
	float enemyFrequency = 2.0f;
	timeSinceEnemy += deltaTime;

	if (timeSinceEnemy.asSeconds() >= enemyFrequency)
	{
		SpawnEnemy();
		timeSinceEnemy = sf::Time();
	}
}

void Game::SetupGame()
{
	sf::Vector2f screenSize(window.getSize());

	//Put our player in the centre of the screen vertically and near the left side.
	playerInstance.SetPosition(sf::Vector2f(100, screenSize.y / 2 - 50));
	obstacleInstance.SetPosition(sf::Vector2f(screenSize.x, screenSize.y / 2 - 50));
	font.loadFromFile("Assets/Graphics/enter-command.ttf");
	scoreText.setFont(font);
	scoreText.setString("Score: 1000");
	scoreText.setPosition(screenSize.x - 300, 100);
}

void Game::SpawnEnemy()
{
	//Special pointer EVERY class has called "this"

	int enemyChoice = rand() % 100;
	int chaseEnemyChance = 50;
}


sf::Vector2f Game::GetScreenSize()
{
	return (sf::Vector2f)window.getSize();
}
