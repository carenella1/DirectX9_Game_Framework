/**********************************
*  Programmer: Austin Ivicevic
*  DirectX 9 Game Engine
*  Date Created: 06/02/2015
***********************************/
#ifndef EVENT_H
#define EVENT_H


namespace Smoke
{
	/////////////////////////////////////////////////////////////////////
	// A listing of all events in the game.
	// 
	// Use this namespace when determining type of event received by a listener
	// - Example: pEvent->Event_Type == Event_Listings::EVENT_PLAYER_INPUT
	/////////////////////////////////////////////////////////////////////
	namespace Event_Listings
	{
		const unsigned int PLAYER_INPUT = 0;
		const unsigned int ENDLEVEL = 1;

		const unsigned int MAX = ENDLEVEL;
	}

	////////////////////
	// EVENT INTERFACE
	////////////////////
	class IEvent
	{
	public:

		/////////////////////////////////////////////////////////////////////
		// Value used by listeners to determine what type of event they've
		// received.
		/////////////////////////////////////////////////////////////////////
		unsigned int Event_Type;


		/////////////////////////////////////////////////////////////////////
		// Determines whether an event should continue to be distributed to
		// other listeners in the Event System or not
		/////////////////////////////////////////////////////////////////////
		bool handledErase;

		IEvent();

	};


	///////////////////
	// Event classes
	///////////////////
	class PlayerInputEvent : public IEvent
	{
	public:

		bool up;
		bool left;
		bool right;
		bool down;
		bool attack;
		bool jump;

		PlayerInputEvent()
		{
			Event_Type = Event_Listings::PLAYER_INPUT;

			up = false;
			left = false;
			right = false;
			down = false;
			attack = false;
		}
	};

	

}	// End of namespace

#endif