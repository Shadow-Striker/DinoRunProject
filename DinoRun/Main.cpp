#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GameObject.h"
#include "Obstacle.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "SFML works!");
	
	sf::Clock gameClock;

	Player myPlayer;
	Obstacle cactus;

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
			sf::Time frameTime = gameClock.restart();
			myPlayer.Update(frameTime);
			cactus.Update(frameTime);

		//Draw
			window.clear();
			myPlayer.Draw(window);
			cactus.Draw(window);
			window.display();
	}

	return 0;
}