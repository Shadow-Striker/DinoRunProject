#include "Animation.h"

Animation::Animation()
	: animFrames()
	, sprite(nullptr)
	, playbackSpeed(15.0f)
	, isLooping(true)
	, timeTillNextFrame()
	, currentFrame(0)
	, isPlaying(true)
{
}

void Animation::AddFrame(sf::Texture* newFrame)
{
	if (newFrame)
	{
		animFrames.push_back(newFrame);
	}
}

void Animation::SetSprite(sf::Sprite* newSprite)
{
	sprite = newSprite;
}

void Animation::SetPlaybackSpeed(float newPlaybackSpeed)
{
	playbackSpeed = newPlaybackSpeed;
}

void Animation::SetLoop(bool newLoop)
{
	isLooping = newLoop;
}

bool Animation::GetIsPlaying()
{
	return isPlaying;
}

void Animation::Update(sf::Time frameTime)
{
	if (!isPlaying) return;

	//Subtract the time passed from the time until the next frame change
	timeTillNextFrame -= frameTime;
	//Determine if it's time to change frames
	if (timeTillNextFrame.asSeconds() <= 0)
	{
		//If it is time,
		//Change the sprite's texture to the next texture
		++currentFrame;

		if (currentFrame >= animFrames.size())
		{
			if (isLooping)
			{
				//If looping reset the animation and show the first frame
				currentFrame = 0;
			}
			else
			{
				//If not looping show the last frame.
				currentFrame = animFrames.size() - 1;
				isPlaying = false;
			}
		}

		if (sprite)
		{
			sprite->setTexture(*animFrames[currentFrame]);
		}

		//Determine the time for the next frame change
		// 
		//Convert our frames per second (FPS) to seconds per frame (SPF)
		float timeToChange = 1.0f / playbackSpeed;
		timeTillNextFrame = sf::seconds(timeToChange);
	}
}

void Animation::Play()
{
	isPlaying = true;

	if (sprite)
	{
		sprite->setTexture(*animFrames[currentFrame]);
	}
}

void Animation::Pause()
{
	isPlaying = false;
}

void Animation::Stop()
{
	isPlaying = false;
	currentFrame = 0;

	if (sprite)
	{
		sprite->setTexture(*animFrames[currentFrame]);
	}

	float timeToChange = 1.0f / playbackSpeed;
	timeTillNextFrame = sf::seconds(timeToChange);
}

