#pragma once

// Library Includes
#include <map>

// Project Includes
#include "Animation.h"

class AnimationSystem
{
	AnimationSystem();

	// Setup
	void SetSprite(sf::Sprite& _sprite);
	Animation& CreateAnimation(std::string _name);

	// Controls
	void Play();
	void Play(std::string _newAnimation);
	void Pause();
	void Stop();

	// Processing
	void Update(sf::Time _frameTime);

private:

	// Settings
	sf::Sprite* m_sprite;
	std::map<std::string, Animation>m_animation;

	// State
	Animation* m_currentAnimation;

};