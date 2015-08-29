/**********************************
*  Programmer: Austin Ivicevic
*  DirectX 9 Game Engine
*  Date Created: 06/02/2015
***********************************/
#pragma once

////////////////////////////////////////
// Include Libraries 
////////////////////////////////////////
#include <Windows.h>
#include <iostream>
#include "stdafx.h"


////////////////////////////////////////
// Libraries / Warning Disable
////////////////////////////////////////
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx10.lib")
#pragma comment (lib, "D3Dcompiler.lib")
#pragma comment (lib, "dxerr")
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")
#pragma warning (disable : 4244)
#pragma warning (disable : 4018)
#pragma warning (disable : 4800)


////////////////////////////////////////
// Include Engine Headers
////////////////////////////////////////
#include "IGameObject.h"
#include "IRenderableObject.h"
#include "EventManager.h"
#include "InputManager.h"
#include "UIManager.h"
#include "Direct3D.h"
#include "Vector.h"
#include "Texture.h"
#include "Timer.h"
#include "Debug.h"


////////////////////////////////////////
// Global Definitions
////////////////////////////////////////
#define WIN32_LEAN_AND_MEAN
LRESULT CALLBACK WndProc(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam);

// Screen parameters
#define SCREEN_DEPTH 1000.0f
#define SCREEN_NEAR 0.1f
#define SCREENW 600
#define SCREENH 600

// Default FPS
#define DEF_FPS 60


////////////////////////////////////////
// Smoke Engine namespace
////////////////////////////////////////
namespace Smoke
{
	class Engine_Core
	{
	private:
		HWND *_window;											// Main game window
		Timer *_coreTimer;										// Main engine timer
		bool _showDebug;										// Flag to show debugger
		int _coreFrameCount;									// Frame count

		////////////////////////
		// Managers / Handlers
		////////////////////////
		EventManager *_eventManager;							// Event manager object
		InputManager *_inputManager;							// Input core object
		UIManager *_uiManager;									// UI object pointer
		Debug *_debugger;										// In-Game debugger
		
		/////////////////////
		// DirectX variables
		/////////////////////
		Direct3D *_directX;										// DirectX wrapper object
		LPDIRECT3DDEVICE9 *_d3dDevice;							// DirectX device
		LPDIRECT3D9 *_d3dContext;								// DirectX context
		LPD3DXSPRITE *_spriteObj;								// Sprite object
		LPDIRECT3DSURFACE9 *_backBuffer;						// Backbuffer pointer

	public:
		Engine_Core();											// Construct an engine object
		~Engine_Core();											// Deconstruct engine object
		bool Initialize(HINSTANCE hInstance, bool fullScrn);	// Initialize all engine cores
		void Shutdown();										// Shutdown engine

		///////////////////////////////
		// Utility functions 
		///////////////////////////////
		void ResetFrameCounter();								// Reset current frame count to 0
		void IncrementFrameCount();								// Increment the frame count by 1
		void ClearScene();										// Clear the scene for rendering
		void EndScene();										// End scene and present

		//////////////////////////////
		// Accessor functions
		//////////////////////////////
		// Return pointers to objects
		EventManager* GetEventManager() { return _eventManager; }		// Return pointer to Event Manager
		InputManager* GetInputManager() { return _inputManager; }		// Return pointer to Input Manager
		UIManager* GetUIManager() { return _uiManager; }				// Return pointer to UI Manager
		Debug* GetDebugger() { return _debugger; }						// Return pointer to Debugger
		Timer* GetCoreTimer() { return _coreTimer; }					// Return pointer to Core Timer

		// Return addresses
		HWND& GetWindowHandle() { return (*_window); }					// Return address of window
		LPDIRECT3DDEVICE9& GetDevice() { return (*_d3dDevice); }		// Return address of d3dDevice
		LPDIRECT3D9& GetContext() { return (*_d3dContext); }			// Return address of d3dContext
		LPD3DXSPRITE& GetSpriteObj() { return (*_spriteObj); }			// Return address of spriteObj
		LPDIRECT3DSURFACE9& GetBackBuffer() { return (*_backBuffer); }	// Return address of backbuffer		
		

		// Return values
		bool ShowDebug() { return _showDebug; }							// Return status of debugger (on/off)
		double GetGameTime() { return _coreTimer->GetElapsed(); }		// Return the current elapsed game time
		int GetFrameCount() { return _coreFrameCount; }					// Return the current frame count
		
		//////////////////////////////
		// Mutator functions
		//////////////////////////////
		void SetShowDebug(bool value) { _showDebug = value; }			// Set status of debugger (on/off)

	};	// End of class
}	// End of namespace

extern std::auto_ptr<Smoke::Engine_Core> g_Engine;	// Global engine object