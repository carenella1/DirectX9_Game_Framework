/**********************************
*  Programmer: Austin Ivicevic
*  DirectX 9 Game Engine
*  Date Created: 06/02/2015
***********************************/
#ifndef TEXTURE_H
#define TEXTURE_H
#include "stdafx.h"

namespace Smoke
{
	class Texture
	{
	private:
		LPDIRECT3DTEXTURE9 _texture;		// Texture to draw on
		D3DXIMAGE_INFO _info;				// Texture info

	public:
		Texture();
		virtual ~Texture();
		void Release();

		/////////////////////
		// Utility functions
		/////////////////////
		bool Load(std::string filename, D3DCOLOR transcolor = D3DCOLOR_XRGB(255, 255, 255));

		//////////////
		// Accessors
		//////////////
		LPDIRECT3DTEXTURE9 GetTexture() { return _texture; }
		int GetWidth() { return _info.Width; }
		int GetHeight() { return _info.Height; }
		RECT GetBounds() { RECT bounds = { 0, 0, _info.Width-1, _info.Height-1}; return bounds; }
	};
}

#endif