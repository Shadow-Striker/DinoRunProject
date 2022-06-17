#include "Player.h"
#include "Game.h"

sf::Texture* Player::playerStand = nullptr;
sf::Texture* Player::playerJump = nullptr;
sf::Texture* Player::playerRun = nullptr;
sf::Texture* Player::playerRunTwo = nullptr;
sf::Texture* Player::playerDuck = nullptr;
sf::Texture* Player::playerDuckTwo = nullptr;

Player::Player(Game* newGame)
	:AnimatingObject()
	, score(0)
	, MOVE_SPEED(100)
	, JUMP_SPEED(300)
	, GRAVITY(1000)
	, velocity(0, 0)
	, isAlive(true)
	, jumpSound()
	, deathSound()
	, playedDeathSound(false)
{
	if (playerStand == nullptr)
	{
		playerStand = new sf::Texture();
		playerStand->loadFromFile("Assets/Graphics/dino-stand.png");
	}

	if (playerRun == nullptr)
	{
		playerRun = new sf::Texture();
		playerRun->loadFromFile("Assets/Graphics/dino-run-1.png");
	}

	if (playerRunTwo == nullptr)
	{
		playerRunTwo = new sf::Texture();
		playerRunTwo->loadFromFile("Assets/Graphics/dino-run-2.png");
	}

	if (playerJump == nullptr)
	{
		playerJump = new sf::Texture();
		playerJump->loadFromFile("Assets/Graphics/dino-jump.png");
	}

	if (playerDuck == nullptr)
	{
		playerDuck = new sf::Texture();
		playerDuck->loadFromFile("Assets/Graphics/dino-crouch-1.png");
	}
	if (playerDuckTwo == nullptr)
	{
		playerDuckTwo = new sf::Texture();
		playerDuckTwo->loadFromFile("Assets/Graphics/dino-crouch-2.png");
	}

	jumpSoundBuffer.loadFromFile("Assets/Sounds/jump.wav");
	jumpSound.setBuffer(jumpSoundBuffer);
	jumpSound.setVolume(5.0f);

	deathSoundBuffer.loadFromFile("Assets/Sounds/death.wav");
	deathSound.setBuffer(deathSoundBuffer);
	deathSound.setVolume(10.0f);
	deathSound.setLoop(false);

	objectSprite.setTexture(*playerStand);
	objectSprite.setPosition(100, 500);


	//Create run animation
	Animation* run = CreateAnim("Run");
	run->AddFrame(playerRun);
	run->AddFrame(playerRunTwo);
	run->SetPlaybackSpeed(10);
	run->SetLoop(false);

	//Create jump animation
	Animation* jump = CreateAnim("Jump");
	jump->AddFrame(playerStand);
	jump->AddFrame(playerJump);
	jump->SetPlaybackSpeed(10);
	jump->SetLoop(false);

	//Create duck animation
	Animation* duck = CreateAnim("Duck");
	duck->AddFrame(playerDuck);
	duck->AddFrame(playerDuckTwo);
	duck->AddFrame(playerStand);
	duck->SetPlaybackSpeed(10);
	duck->SetLoop(false);

	//Setup player collider
	modifiedCollider.left = 45;
	modifiedCollider.top = 73;
	modifiedCollider.width = 102 - modifiedCollider.left;
	modifiedCollider.height = 140 - modifiedCollider.top;

}

void Player::Update(sf::Time frameTime)
{
	velocity.x = 0;
	score++;

	Play("Run");

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && GetPosition().y >= 100.0f)
	{
		Jump();		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Duck();
	}
	
	if (!isAlive && !playedDeathSound)
	{
		deathSound.play();
		playedDeathSound = true;
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
	jumpSound.play();
	velocity.y = -JUMP_SPEED;
	Play("Jump");
}

void Player::Duck()
{
	Play("Duck");
}

bool Player::GetAlive()
{
	return isAlive;
}

int Player::GetScore()
{
	return score;
}

void Player::ResetScore()
{
	score = 0;
}


void Player::SetAlive(bool _isAlive)
{
	isAlive = _isAlive;
}

void Player::Collision()
{
}
