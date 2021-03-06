#include "Obstacle.h"

sf::Texture* Obstacle::obstacleTexture = nullptr;

Obstacle::Obstacle()
	:  moveSpeed(-500)
	, spawnPosition(1000,1000)
	, hitSFX()
	, MOVE_SPEED(1)
{
	int obstacleChoice = rand() % 100;
	int flyingObstacleChance = 50;

	if (obstacleTexture == nullptr)
	{
		obstacleTexture = new sf::Texture();
		obstacleTexture->loadFromFile("Assets/Graphics/cactus.png");
	}
	objectSprite.setPosition(spawnPosition);
	objectSprite.setTexture(*obstacleTexture);

	//Setup obstacle collider
	modifiedCollider.left = -10;
	modifiedCollider.top = 35;
	modifiedCollider.width = 102 - modifiedCollider.left;
	modifiedCollider.height = 140 - modifiedCollider.top;
}

void Obstacle::Update(sf::Time frameTime)
{
	moveSpeed -= .025f;
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

void Obstacle::OnCollision(GameObject _collisionObject)
{
	if (IsColliding(_collisionObject))
	{
		
	}
}
