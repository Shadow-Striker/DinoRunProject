#pragma once
#include<SFML/Audio.hpp>
#include "GameObject.h"
class Obstacle :
	public GameObject
{
public:
	Obstacle();
	virtual void Update(sf::Time frameTime) override;

private:
	static sf::Texture* obstacleTexture;
	float moveSpeed;
	sf::Vector2f spawnPosition;
	sf::Sound hitSFX;

	sf::Vector2f velocity;
	const float MOVE_SPEED;

protected:
	void OnCollision();
};

