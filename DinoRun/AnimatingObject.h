#pragma once
#include "GameObject.h"
#include "Animation.h"
#include <string>
class AnimatingObject :
    public GameObject
{
public:
    AnimatingObject();

    //Setup
    Animation* CreateAnim(std::string animName);

    //Controls
    void Play();
    void Play(std::string newAnim);
    void Pause();
    void Stop();

    //Processing (override ensures we override the Update() in GameObject class.
    virtual void Update(sf::Time frameTime) override;

private:
    //We are creating a "map" which is basically a Dictionary from c#
    std::map<std::string, Animation> animationsMap;
    Animation* currentAnim;
};

