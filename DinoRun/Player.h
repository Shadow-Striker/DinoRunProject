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
    void Duck();
    bool GetAlive();
    int GetScore();
    void ResetScore();
    void SetAlive(bool _isAlive);
    void Collision();
    virtual void Update(sf::Time frameTime) override;
    //Player(sf::Sprite _playerSprite, sf::Vector2f _playerPos);

private:
    static sf::Texture* playerStand;
    static sf::Texture* playerRun;
    static sf::Texture* playerRunTwo;
    static sf::Texture* playerJump;
    static sf::Texture* playerDuck;
    static sf::Texture* playerDuckTwo;

    sf::Vector2f velocity;
    int score;
    const float MOVE_SPEED;
    const float JUMP_SPEED;
    const float GRAVITY;
    static sf::Texture* playerTexture;
    bool isAlive;
    bool playedDeathSound;
    sf::Sound jumpSound;
    sf::Sound deathSound;
    sf::SoundBuffer jumpSoundBuffer;
    sf::SoundBuffer deathSoundBuffer;

};



