/**********************************
*  Programmer: Austin Ivicevic
*  DirectX 9 Game Engine
*  Date Created: 06/02/2015
***********************************/
#include "Engine_Core.h"

namespace Smoke
{
	Texture::Texture()
	{
		_texture = NULL;
	}


	Texture::~Texture() {}


	void Texture::Release()
	{
		if (_texture)
		{
			if (_texture->Release() > 0)
				debug << "\tFailed to release a texture" << std::endl;
		}
	}


	/////////////////////
	// Utility functions
	/////////////////////
	bool Texture::Load(std::string filename, D3DCOLOR transColor)
	{
		HRESULT result;

		// Get width and height from bitmap file
		// and store in our _info object
		result = D3DXGetImageInfoFromFile(filename.c_str(), &_info);
		if (result != D3D_OK)
		{
			debug << "\tUnable to get image info" << std::endl;
			_texture = NULL;
			return false;
		}

		// Create the new texture with bitmap file
		D3DXCreateTextureFromFileEx(
			g_Engine->GetDevice(),	// Direct3D device object
			filename.c_str(),		// Bitmap filename
			_info.Width,            // Bitmap image width
			_info.Height,           // Bitmap image height
			1,						// Mip-map levels (1 for no chain)
			D3DPOOL_DEFAULT,		// Type of surface (standard)
			D3DFMT_UNKNOWN,			// Surface format (default)
			D3DPOOL_DEFAULT,		// Memory class for the texture
			D3DX_DEFAULT,			// Image filter
			D3DX_DEFAULT,			// Mip filter
			transColor,				// Color key for transparency
			&_info,                 // Bitmap file info (from loaded file)
			NULL,					// Color palette
			&_texture);				// Destination texture

		// Check that texture was created successfully
		if (result != D3D_OK)    
		{
			debug << "\tFailed to create texture from file" << std::endl;
			_texture = NULL;
			return false;
		}

		return true;
	}
}