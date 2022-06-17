#pragma once
#include<SFML/Audio.hpp>
#include "GameObject.h"
#include "AnimatingObject.h"
class Obstacle :
	public AnimatingObject
{
public:
	Obstacle();
	virtual void Update(sf::Time frameTime) override;
	void OnCollision(GameObject _collisionObject);

protected:
	float moveSpeed;
	sf::Vector2f spawnPosition;
	sf::Sound hitSFX;

	sf::Vector2f velocity;
	const float MOVE_SPEED;

private:
	static sf::Texture* obstacleTexture;

};

