/**********************************
*  Programmer: Austin Ivicevic
*  DirectX 9 Game Engine
*  Date Created: 06/02/2015
***********************************/
#include "Engine_Core.h"
#include "Sprite.h"

namespace Smoke
{
	Sprite::Sprite()
		: IEntity()
	{
		_textureLoaded = false;
		_texture = NULL;
	}


	Sprite::~Sprite()
	{
		if (_textureLoaded)
		{
			delete _texture;
			_texture = NULL;
		}
	}


	bool Sprite::Initialize(std::string filename, Vector2 pos, 
		Vector2 velocity, D3DCOLOR transColor)
	{
		// Flag for initialization errors
		bool result;		

		// Make sure texture is NULL
		if (_texture)
		{
			delete _texture;
			_texture = NULL;
		}

		// Create a new texture
		_texture = new Texture();
		result = _texture->Load(filename, transColor);
		if (!result)
		{
			debug << "\tError loading texture for sprite" << std::endl;
			return false;
		}
		else
			_textureLoaded = true;

		//////////////////////////
		// Set sprite properties
		//////////////////////////
		_pos = pos;
		_velocity = velocity;

		// Get sprite size
		_size.x = _texture->GetWidth();
		_size.y = _texture->GetHeight();

		return true;
	}


	void Sprite::Update(float deltaTime)
	{
		// Apply the velocity to sprites each frame
		// Note: Limit this with deltaTime
		_pos += _velocity;
	}


	void Sprite::Render()
	{
		g_Engine->GetSpriteObj()->Draw(_texture->GetTexture(),
			NULL, NULL, &_pos.ToD3DXVECTOR3(), D3DCOLOR_XRGB(255, 255, 255));
	}


	void Sprite::HandleEvent(IEvent* pEvent)
	{
		return;
	}


	// Accessor
	bool Sprite::ImageLoaded() 
	{ 
		if (_texture->GetTexture() != NULL)
			return true;
		else
			return false; 
	}

}