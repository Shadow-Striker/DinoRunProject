#include "Player.h"

sf::Texture* Player::playerStand = nullptr;
sf::Texture* Player::playerJump = nullptr;

Player::Player(Game* newGame)
	:AnimatingObject()
	, MOVE_SPEED(100)
	, JUMP_SPEED(300)
	, GRAVITY(1000)
	, velocity(0, 0)
{
	if (playerStand == nullptr)
	{
		playerStand = new sf::Texture();
		playerStand->loadFromFile("Assets/Graphics/dino-stand.png");
	}

	if (playerJump == nullptr)
	{
		playerJump = new sf::Texture();
		playerJump->loadFromFile("Assets/Graphics/dino-jump.png");
	}

	objectSprite.setTexture(*playerStand);
	objectSprite.setPosition(100, 500);

	//Create the animation
	Animation* jump = CreateAnim("Jump");
	jump->AddFrame(playerStand);
	jump->AddFrame(playerJump);
	jump->SetPlaybackSpeed(10);
	jump->SetLoop(false);

	Play("Jump");

	//Setup player collider
	modifiedCollider.left = 45;
	modifiedCollider.top = 73;
	modifiedCollider.width = 102 - modifiedCollider.left;
	modifiedCollider.height = 140 - modifiedCollider.top;

}

void Player::Update(sf::Time frameTime)
{
	velocity.x = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x = -MOVE_SPEED;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x = MOVE_SPEED;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Jump();
	}

	//update velocity based on gravity
	velocity.y += GRAVITY * frameTime.asSeconds();

	//Stop falling after reaching a certain position
	if (GetPosition().y >= 500.0f)
	{
		SetPosition(sf::Vector2f(GetPosition().x, 500.0f));
	}

	//Update position based on velocity
	SetPosition(GetPosition() + velocity * frameTime.asSeconds());
	AnimatingObject::Update(frameTime);
}

void Player::Jump()
{
	velocity.y = -JUMP_SPEED;
	Play("Jump");
}

bool Player::GetAlive()
{
	return false;
}


void Player::SetAlive(bool nowAlive)
{

}

void Player::Collision()
{

}
