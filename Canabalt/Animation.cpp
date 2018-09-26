// Project Includes
#include "Animation.h"

Animation::Animation()
	: m_frames()
	, m_sprite(nullptr)
	, m_playBackSpeed(15.0f)
	, m_loop(false)
	, m_playing(false)
	, m_nextFrameChange()
	, m_currentFrame(0)
{

}

void Animation::Update(sf::Time _frameTime)
{
	// Is it time to change to a new frame?
	m_nextFrameChange -= _frameTime;
	if (m_nextFrameChange.asSeconds() <= 0)
	{
		// It's time to change the frame!

		// change to the next frame
		++m_currentFrame;

		//Did we reach the end
		if (m_currentFrame >= m_frames.size())
		{
			//We did reach the end!

			// TODO: What if no loop?

			//Wrap around to the beginning
			m_currentFrame = 0;
		}

		if (m_sprite) // is not - 0 aka null aka nullptr
		{
			m_sprite->setTexture(*m_frames[m_currentFrame]);
		}
	}
}


void Animation