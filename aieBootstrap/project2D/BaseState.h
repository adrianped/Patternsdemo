#pragma once
#include "Renderer2D.h"
#include "Texture.h"

using namespace aie;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Forward declaration to avoid circular inclusion
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class StateMachine;

class BaseState
{
public:
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Constuctor to initiate the class and all its variables
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	BaseState(){}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Destructor to delete or clear up the memory to ensure that there are no memory leaks 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	~BaseState(){}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Function in charge of any operations done when this state is entered
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	virtual void OnEnter() = 0;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Function that controls the updating for this state
	//Taking in delta time to conduct any calculations that require time
	//And a state machine pointer to change states when Timer has finished
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	virtual void OnUpdate(float fDeltaTime, StateMachine * State) = 0;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Function that draws all sprites and objects to the screen
	//Taking in a Renderer2D pointer to draw the object to the window
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	virtual void OnDraw(Renderer2D* m_2dRenderer) = 0;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Function in charge of any operations done when this state is exited
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	virtual void OnExit() = 0;
};

