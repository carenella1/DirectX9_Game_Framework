/**********************************
*  Programmer: Austin Ivicevic
*  DirectX 9 Game Engine
*  Date Created: 06/02/2015
***********************************/
#include "EntityManager.h"
#include "Engine_Core.h"

namespace Smoke
{
	EntityManager::EntityManager()
	{

	}


	EntityManager::~EntityManager() {}


	void EntityManager::AddEntity(IEntity* e)
	{
		if (e != NULL)
		{
			_entities.push_back(e);
		}	
	}


	void EntityManager::UpdateEntities(float deltaTime)
	{
		// Check if entities exist
		if (!_entities.empty())
		{
			// Go through each entity
			BOOST_FOREACH(IEntity *e, _entities)
			{
				
			}
		}
	}


	void EntityManager::RenderEntities2D()
	{
		// Check if entities exist
		if (!_entities.empty())
		{
			// Go through each entity
			BOOST_FOREACH(IEntity *e, _entities)
			{
				
			
			}
		}
	}


	void EntityManager::RenderEntities3D()
	{
		// Check if entities exist
		if (!_entities.empty())
		{
			// Go through each entity
			BOOST_FOREACH(IEntity *e, _entities)
			{
				
			}
		}
	}


	void EntityManager::DrawEntities()
	{
		// Check if entities exist
		if (!_entities.empty())
		{
			// Go through each entity
			BOOST_FOREACH(IEntity *e, _entities)
			{

			}
		}
	}


	void EntityManager::BuryEntities()
	{
		// Check if entities exist
		if (!_entities.empty())
		{
			// Go through each entity
			BOOST_FOREACH(IEntity *e, _entities)
			{

			}
		}
	}


	void EntityManager::Shutdown()
	{
		// Check if entities still exist
		if (!_entities.empty())
		{
			// Go through remaining entities
			BOOST_FOREACH(IEntity *e, _entities)
			{
				// TODO: Delete entities
				
			}
			_entities.clear();	// Clear out the vector
		}
	}


	/////////// Accessors /////////////
	IEntity* EntityManager::GetEntity(std::string entityName)
	{
		if (!_entities.empty())
		{
			BOOST_FOREACH(IEntity *e, _entities)
			{
				
			}
		}
		debug << "\tEntity: " << entityName << " not found" << std::endl;
		return NULL;
	}
}