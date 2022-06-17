#pragma once
#include "AnimatingObject.h"

class Player :
    public AnimatingObject
{
public:

    Player();
    void Jump();
    bool GetAlive();
    void SetAlive(bool nowAlive);
    virtual void Update(sf::Time frameTime) override;
    //Player(sf::Sprite _playerSprite, sf::Vector2f _playerPos);

private:
    static sf::Texture* playerStand;
    static sf::Texture* playerJump;

    sf::Vector2f velocity;
    const float MOVE_SPEED;
    const float JUMP_SPEED;
    const float GRAVITY;
    static sf::Texture* playerTexture;

};



