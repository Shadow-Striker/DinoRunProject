#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GameObject.h"
#include "Obstacle.h"
#include "Game.h"

int main()
{
	/*sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "SFML works!");
	sf::Font font;
	sf::Text text;
	sf::Clock gameClock;

	Player myPlayer;
	Obstacle cactus;
	cactus.SetPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width, 500));
	font.loadFromFile("Assets/Graphics/enter-command.ttf");
	text.setFont(font);
	text.setString("Test");
	text.setPosition(100, 100);
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
			window.draw(text);
			window.display();
	}*/
	Game ourGame;
	ourGame.Run();
	return 0;
}