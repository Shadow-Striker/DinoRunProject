#include "Obstacle.h"

sf::Texture* Obstacle::obstacleTexture = nullptr;

Obstacle::Obstacle()
	:  moveSpeed(-500)
	, spawnPosition(1000,1000)
	, hitSFX()
	, MOVE_SPEED(1)
{
	if (obstacleTexture == nullptr)
	{
		obstacleTexture = new sf::Texture();
		obstacleTexture->loadFromFile("Assets/Graphics/cactus.png");
	}
	objectSprite.setPosition(spawnPosition);
	objectSprite.setTexture(*obstacleTexture);
}

void Obstacle::Update(sf::Time frameTime)
{
	velocity.x = moveSpeed;
	//Update position based on velocity
	if (GetPosition().x > -1000)
	{
		SetPosition(GetPosition() + velocity * frameTime.asSeconds());
	}
}

void Obstacle::OnCollision(GameObject _collisionObject)
{
	if (IsColliding(_collisionObject))
	{
		
	}
}
