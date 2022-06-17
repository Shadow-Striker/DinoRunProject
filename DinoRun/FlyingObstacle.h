#pragma once
#include "Obstacle.h"
class FlyingObstacle :
    public Obstacle
{
public:
	FlyingObstacle();
	virtual void Update(sf::Time frameTime) override;

private:
	static sf::Texture* flyingOneTexture;
	static sf::Texture* flyingTwoTexture;
};

