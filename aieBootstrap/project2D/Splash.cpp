#include "Splash.h"
#include "StateMachine.h"
#include "Input.h"
#include <assert.h>

using namespace aie;
//---------------------------------------------------------------------------------------
Splash::Splash()
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Creates all sprites for the splash state 
	//And asserts to ensure they are created successfully
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m_pSplash = new Texture("./textures/Splash.png");
	assert(m_pSplash);

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
Splash::~Splash()
{
	delete m_pSplash;
}

//---------------------------------------------------------------------------------------
void Splash::OnEnter()
{//LEFT EMPTY
}
//---------------------------------------------------------------------------------------

void Splash::OnUpdate(float fDeltaTime, StateMachine * State)
{
	Input* input = Input::getInstance();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Timer For sprites
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	x += fDeltaTime / 1.5;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Once 3 seconds has elapsed, the state will change to Loading
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	time += fDeltaTime;
	if (time >= 3)
		State->PushState(1);
}
//---------------------------------------------------------------------------------------

void Splash::OnDraw(Renderer2D * m_2dRenderer)
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Draws sprite
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m_2dRenderer->drawSprite(m_pSplash, 650, 360);
}

//---------------------------------------------------------------------------------------
void Splash::OnExit()
{//LEFT EMPTY
}
