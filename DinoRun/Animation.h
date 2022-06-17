#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
class Animation
{
public:
	//Constructors/Destructor
	Animation();

	//Getters/Setters
	void AddFrame(sf::Texture* newFrame);
	void SetSprite(sf::Sprite* newSprite);
	void SetPlaybackSpeed(float newPlaybackSpeed);
	void SetLoop(bool newLoop);
	bool GetIsPlaying();

	//Processing and controls
	void Update(sf::Time frameTime);
	void Play();
	void Pause();
	void Stop();

private:

	std::vector<sf::Texture*> animFrames;
	sf::Sprite* sprite;
	float playbackSpeed;
	bool isLooping;

	//State
	sf::Time timeTillNextFrame;
	int currentFrame;
	bool isPlaying;
};

