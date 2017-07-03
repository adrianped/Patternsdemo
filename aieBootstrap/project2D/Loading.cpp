#include "Loading.h"
#include "Input.h"
#include "StateMachine.h"
#include <assert.h>


//---------------------------------------------------------------------------------------
Loading::Loading()
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Creates all sprites for the Loading state 
	//And asserts to ensure they are created successfully
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m_pLoading = new Texture("./textures/Loading.png");
	assert(m_pLoading);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Times how long you are in the state for
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	time = 0;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Variable to set the timer for the sprites
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	x = 0;
}

//---------------------------------------------------------------------------------------
Loading::~Loading()
{
	delete m_pLoading;
}

//---------------------------------------------------------------------------------------
void Loading::OnEnter()
{//LEFT BLANK
}

//---------------------------------------------------------------------------------------
void Loading::OnUpdate(float fDeltaTime, StateMachine * State)
{
	Input* input = Input::getInstance();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Timer For sprites
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	x += fDeltaTime / 1.5;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Once 3 seconds has elapsed, the state will change to Menu
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	time += fDeltaTime;
	if (time >= 3)
		State->PushState(2);
}

//---------------------------------------------------------------------------------------
void Loading::OnDraw(Renderer2D * m_2dRenderer)
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Draws sprite
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m_2dRenderer->drawSprite(m_pLoading, 650, 360);
}

//---------------------------------------------------------------------------------------
void Loading::OnExit()
{//LEFT BLANK
}
