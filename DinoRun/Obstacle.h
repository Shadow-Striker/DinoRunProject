#pragma once
#include<SFML/Audio.hpp>
#include "GameObject.h"
class Obstacle :
	public GameObject
{
public:
	Obstacle();
	virtual void Update(sf::Time frameTime) override;
	void OnCollision(GameObject _collisionObject);

private:
	static sf::Texture* obstacleTexture;
	float moveSpeed;
	sf::Vector2f spawnPosition;
	sf::Sound hitSFX;

	sf::Vector2f velocity;
	const float MOVE_SPEED;

};

