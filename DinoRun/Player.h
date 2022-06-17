#pragma once
#include "AnimatingObject.h"
#include <SFML/Audio.hpp>
class Game;

class Player :
    public AnimatingObject
{
public:

    Player(Game* newGame);
    void Jump();
    bool GetAlive();
    int GetScore();
    void SetAlive(bool _isAlive);
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
    bool isAlive;
    sf::Sound jumpSound;
    sf::SoundBuffer soundBuffer;

};



