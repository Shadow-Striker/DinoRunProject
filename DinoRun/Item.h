#pragma once
#include "Obstacle.h"
class Item :
    public Obstacle
{
public:
    Item();
    virtual void Update(sf::Time frameTime) override;
    void BoostScore(int _score);
private:
    int scoreBoostAmount;
    sf::Sound pickupSFX;
    sf::SoundBuffer pickupBuffer;
    static sf::Texture* itemTexture;
};

