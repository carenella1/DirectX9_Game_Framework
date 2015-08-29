/**********************************
*  Programmer: Austin Ivicevic
*  DirectX 9 Game Engine
*  Date Created: 06/02/2015
***********************************/
#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <vector>
#include "IEntity.h"
#include "stdafx.h"
#include "Sprite.h"

namespace Smoke
{
	class EntityManager
	{
	private:
		std::vector<IEntity*> _entities;		// Vector of entities

	public:
		EntityManager();
		virtual ~EntityManager();
		void AddEntity(IEntity *e);				
		void UpdateEntities(float deltaTime);
		void RenderEntities2D();
		void RenderEntities3D();
		void DrawEntities();					// For use if rendering not needed
		void BuryEntities();					// Remove expired entities from vector
		void Shutdown();						// Shutdown manager

		//////// Accessors //////////
		IEntity* GetEntity(std::string entityName);

	};	// End of class
}	// End of namespace
#endif