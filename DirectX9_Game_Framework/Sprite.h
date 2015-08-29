/**********************************
*  Programmer: Austin Ivicevic
*  DirectX 9 Game Engine
*  Date Created: 06/02/2015
***********************************/
#ifndef SPRITE_H
#define SPRITE_H
#include "IEntity.h"
#include "Texture.h"
#include "Vector.h"

namespace Smoke
{
	class Sprite : public IEntity
	{
	private:
		Vector2 _pos;				// Sprite x and y position
		Vector2 _prevPos;			// Sprite previous x and y position
		Vector2 _velocity;			// Sprite x and y velocity
		Vector2 _size;				// Sprite size
		Texture *_texture;			// Sprite texture pointer
		bool _textureLoaded;		// Returns true if (_texture->GetTexture() != NULL)

	public:
		Sprite();
		virtual ~Sprite();
		bool Initialize(std::string filename, Vector2 pos, Vector2 velocity,
			D3DCOLOR transColor = D3DCOLOR_XRGB(255, 255, 255));
		void Update(float deltaTime) override;
		void Render() override;
		void HandleEvent(IEvent *e) override;

		///////////////////////
		// Accessor functions
		///////////////////////
		double GetPosX() { return _pos.GetX(); }
		double GetPosY() { return _pos.GetY(); }
		Vector2 GetPos() { return _pos; }
		double GetVelX() { return _velocity.GetX(); }
		double GetVelY() { return _velocity.GetY(); }
		Vector2 GetVelocity() { return _velocity; }
		int GetWidth() { return (int)_size.GetX(); }
		int GetHeight() { return (int)_size.GetY(); }
		RECT GetBounds() { return _texture->GetBounds(); }
		bool ImageLoaded();

		///////////////////////
		// Mutator functions
		///////////////////////
		void SetVelX(double x1) { _velocity.x = x1; }
		void SetVelY(double y1) { _velocity.y = y1; }
		void SetVelocity(Vector2 velocity) { _velocity = velocity; }
	};
}

#endif