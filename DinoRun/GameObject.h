#pragma once
#include <SFML/Graphics.hpp>
class GameObject
{
public:
	GameObject();

	void Draw(sf::RenderTarget& target);
	virtual void Update(sf::Time frameTime);
	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f newPosition);
	sf::FloatRect GetCollider();
	sf::Vector2f GetCollisionDepth(GameObject& other);
	bool IsColliding(GameObject& other);
	sf::RectangleShape rectDisplay;


protected:
	sf::Sprite objectSprite;
	sf::FloatRect modifiedCollider;


private:
	sf::Vector2f objectPosition;
};


