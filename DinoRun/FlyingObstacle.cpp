#include "FlyingObstacle.h"
#include "AnimatingObject.h"

sf::Texture* FlyingObstacle::flyingOneTexture = nullptr;
sf::Texture* FlyingObstacle::flyingTwoTexture = nullptr;
FlyingObstacle::FlyingObstacle()
{
	if (flyingOneTexture == nullptr)
	{
		flyingOneTexture = new sf::Texture();
		flyingOneTexture->loadFromFile("Assets/Graphics/flyer-1.png");
	}
	if (flyingTwoTexture == nullptr)
	{
		flyingTwoTexture = new sf::Texture();
		flyingTwoTexture->loadFromFile("Assets/Graphics/flyer-2.png");
	}
	objectSprite.setTexture(*flyingOneTexture);
	objectSprite.setPosition(spawnPosition);

	//Create the animation
	Animation* flying = CreateAnim("Flying");
	flying->AddFrame(flyingOneTexture);
	flying->AddFrame(flyingTwoTexture);
	flying->SetPlaybackSpeed(10);
	flying->SetLoop(true);

	Play("Flying");

	//Setup obstacle collider
	modifiedCollider.left = 45;
	modifiedCollider.top = 73;
	modifiedCollider.width = 102 - modifiedCollider.left;
	modifiedCollider.height = 140 - modifiedCollider.top;
}

void FlyingObstacle::Update(sf::Time frameTime)
{
	moveSpeed -= .01f;
	velocity.x = moveSpeed;
	//Update position based on velocity
	//If the obstacle is off the left side of the screen, move it back to the right side of the screen
	if (GetPosition().x > -10)
	{
		SetPosition(GetPosition() + velocity * frameTime.asSeconds());
	}
	else
	{
		SetPosition(sf::Vector2f(2000, 300));
	}

	//rectDisplay.setPosition(sf::Vector2f(GetCollider().left, GetCollider().top));
	//rectDisplay.setSize(sf::Vector2f(GetCollider().width, GetCollider().height));
	//rectDisplay.setFillColor(sf::Color::Green);
	AnimatingObject::Update(frameTime);

}
