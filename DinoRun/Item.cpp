#include "Item.h"

sf::Texture* Item::itemTexture = nullptr;

Item::Item()
 : scoreBoostAmount(0)
 , pickupSFX()
{
	if (itemTexture == nullptr)
	{
		itemTexture = new sf::Texture();
		itemTexture->loadFromFile("Assets/Graphics/pickup.png");
	}
	objectSprite.setPosition(spawnPosition);
	objectSprite.setTexture(*itemTexture);

	pickupBuffer.loadFromFile("pickup.wav");
	pickupSFX.setBuffer(pickupBuffer);

	//Setup obstacle collider
	modifiedCollider.left = 45;
	modifiedCollider.top = 73;
	modifiedCollider.width = 102 - modifiedCollider.left;
	modifiedCollider.height = 140 - modifiedCollider.top;
}

void Item::Update(sf::Time frameTime)
{
	moveSpeed -= .05f;
	velocity.x = moveSpeed;

	//Update position based on velocity
   //If the obstacle is off the left side of the screen, move it back to the right side of the screen
	if (GetPosition().x > -10)
	{
		SetPosition(GetPosition() + velocity * frameTime.asSeconds());
	}
	else
	{
		SetPosition(sf::Vector2f(2000, 500));
	}

	//rectDisplay.setPosition(sf::Vector2f(GetCollider().left, GetCollider().top));
	//rectDisplay.setSize(sf::Vector2f(GetCollider().width, GetCollider().height));
	//rectDisplay.setFillColor(sf::Color::Green);
}

void Item::BoostScore(int _score)
{
	pickupSFX.play();
	_score += scoreBoostAmount;
}
