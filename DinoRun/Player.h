#pragma once
#include "AnimatingObject.h"
class Game;

class Player :
    public AnimatingObject
{
public:

    Player(Game* newGame);
    void Jump();
    bool GetAlive();
    int GetScore();
    void SetAlive(bool nowAlive);
    void Collision();
    virtual void Update(sf::Time frameTime) override;
    //Player(sf::Sprite _playerSprite, sf::Vector2f _playerPos);

private:
    static sf::Texture* playerStand;
    static sf::Texture* playerJump;

    sf::Vector2f velocity;
    int score;
    const float MOVE_SPEED;
    const float JUMP_SPEED;
    const float GRAVITY;
    static sf::Texture* playerTexture;

};



