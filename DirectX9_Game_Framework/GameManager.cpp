/**********************************
*  Programmer: Austin Ivicevic
*  DirectX 9 Game Engine
*  Date Created: 06/02/2015
***********************************/
#include "GameManager.h"

namespace Smoke
{
	///////////////////////////
	// Level load functions
	///////////////////////////
	void Level1()
	{
		// Load all object for Level1
		
	}



	GameManager::GameManager()
	{
		endProgram = false;
		gameOver = false;			
		_frameInterval = DEF_FPS;	// Set default fps
		GameObjects.clear();		// Clear vector of GameObjects

		lvlPtr = &Level1;			// Set default level to Level1
	}


	GameManager::~GameManager()
	{

	}


	////////////////////////////////////////
	// Initialize game resources
	////////////////////////////////////////
	bool GameManager::Game_Init()
	{
		srand(time(NULL));

		////////////////////////
		// Setup Input devices
		////////////////////////
		Keyboard *pKeyboard = new Keyboard();
		g_Engine->GetInputManager()->SetKeyboard(pKeyboard);

		// Key codes
		std::vector<int> codes;
		codes.push_back(DIK_SPACE);
		g_Engine->GetInputManager()->SetDIKKeyboardCodes(codes);

		return true;

		// Register event listeners...
	}


	void GameManager::LoadLevel()
	{
		// Invoke the function that lvlPtr points to
		lvlPtr();

		// Reset the gameOver flag so that the next level can begin
		gameOver = false;
	}


	////////////////////////////////////////
	// Quick update to get GameTime
	////////////////////////////////////////
	void GameManager::Update(float deltaTime)
	{
		/////////////////////////////////
		// Updates various managers
		/////////////////////////////////
		g_Engine->IncrementFrameCount();
		g_Engine->GetInputManager()->Update(deltaTime);
		g_Engine->GetDebugger()->Update(deltaTime);

		///////////////////////////////
		// Manage game object updates
		///////////////////////////////
		for (goIt = GameObjects.begin(); goIt != GameObjects.end(); ++goIt)
		{
			(*goIt)->Update(deltaTime);
		}
	}


	void GameManager::Game_Render()
	{
		/////////////////////////////////////////////////////////
		// Clear the backbuffer, render all renderable objects
		// then end the scene and present to game screen
		/////////////////////////////////////////////////////////
		g_Engine->ClearScene();								// Clear the backbuffer for rendering
		if (g_Engine->GetDevice()->BeginScene() == D3D_OK)	// Begin scene
		{
			//////////////////////////////
			// Begin Spritebatch for 2D
			g_Engine->GetSpriteObj()->Begin(D3DXSPRITE_ALPHABLEND);

			

			if (g_Engine->ShowDebug())
			{
				// Determine if rendering is possible
				IRenderableObject *_debug = dynamic_cast<IRenderableObject*>(g_Engine->GetDebugger());
				if (_debug)
					_debug->Render();		// Render the in-game debugger
			}

			g_Engine->GetSpriteObj()->End();
			// End Spritebatch for 2D
			//////////////////////////////


			// 3D rendering will go here....

			g_Engine->EndScene();		// End scene and present backbuffer
		}
	}


	void GameManager::HandleEvent(IEvent *pEvent)
	{
		return;
	}


	////////////////////////////////////////
	// Free game specific resources
	////////////////////////////////////////
	void GameManager::Game_End()
	{
		// Remove any current game objects
		PurgeGameObjects();

		// Deallocate any other memory here.
	}


	////////////////////////////////////////
	// Utility Functions
	////////////////////////////////////////
	void GameManager::PurgeGameObjects()
	{
		// Deallocate any memory before switching to the new vector
		for (goIt = GameObjects.begin(); goIt != GameObjects.end();
			/* INTENTIONALLY LEFT BLANK */)
		{
			delete (*goIt);
			goIt = GameObjects.erase(goIt);
		}
	}
}
