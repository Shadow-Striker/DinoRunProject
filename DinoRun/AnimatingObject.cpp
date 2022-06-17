#include "AnimatingObject.h"
#include "GameObject.h"

AnimatingObject::AnimatingObject()
	: GameObject()
	, animationsMap()
	, currentAnim(nullptr)
{
}

Animation* AnimatingObject::CreateAnim(std::string animName)
{
	Animation* newAnim = &(animationsMap[animName]);
	newAnim->SetSprite(&objectSprite);
	return newAnim;
}

void AnimatingObject::Play()
{
	if (currentAnim)
		currentAnim->Play();
}

void AnimatingObject::Play(std::string newAnim)
{
	//What if our current animation is the one we're trying to play?
	//This would stop it, so we'd constantly be on frame 1.
	//Could add an if check to ensure the new animation is different from the current one.
	Stop();

	//This animation may not exist so check that before accessing the map
	currentAnim = &(animationsMap[newAnim]);

	Play();
}

void AnimatingObject::Pause()
{
	if (currentAnim)
		currentAnim->Pause();
}

void AnimatingObject::Stop()
{
	if (currentAnim)
		currentAnim->Stop();
}



void AnimatingObject::Update(sf::Time frameTime)
{
	GameObject::Update(frameTime);

	if (currentAnim)
		currentAnim->Update(frameTime);
}

