/**********************************
*  Programmer: Austin Ivicevic
*  DirectX 9 Game Engine
*  Date Created: 06/02/2015
***********************************/
#include "Engine_Core.h"

namespace Smoke
{
	Debug::Debug()
	{
		// Register listeners for this object
		g_Engine->GetEventManager()->RegisterListener(this, Event_Listings::PLAYER_INPUT);

		buttonPressed = false;
	}


	Debug::~Debug() {}


	bool Debug::Initialize()
	{
		_coreFrameRate = 0;
		_gameTime = 0;
		_deltaTime = 0;
		_fontObject = Font("Calibri", 24);

		return true;
	}


	void Debug::Update(float deltaTime)
	{
		//added during final chapter
		if (deltaTime == 0) deltaTime = 0.01667f;
		else _deltaTime = deltaTime;				// Get delta time
		
		_gameTime = g_Engine->GetGameTime() * 0.001;// Get current game time
		CalcFrameRate();
	}


	void Debug::HandleEvent(IEvent *e)
	{
		// Testing events
		if (e->Event_Type == Event_Listings::PLAYER_INPUT)
		{
			if (buttonPressed) buttonPressed = false;
			else if (!buttonPressed) buttonPressed = true;
		}
	}


	void Debug::Render()
	{
		std::ostringstream oss;
		oss.imbue(std::locale("english-us"));
		oss << "Game time: " << _gameTime << std::endl;
		oss << "Delta time: " << _deltaTime << std::endl;
		oss << "Core fps: " << (unsigned long)_coreFrameRate << std::endl;
		oss << "Button Test: ";
		if (buttonPressed) oss << "Yes" << std::endl;
		else oss << "No" << std::endl;
		_fontObject.Print(0, 0, oss.str(), D3DCOLOR_XRGB(255, 255, 255));
	}


	void Debug::Shutdown()
	{

	}


	//////////////////////
	// Utility functions
	//////////////////////
	void Debug::CalcFrameRate()
	{
		// After one second...
		if (_frameTimer.Stopwatch(1000))	
		{
			_coreFrameRate = g_Engine->GetFrameCount();	// Get fps
			g_Engine->ResetFrameCounter();				// Reset frame count
		}
	}
}