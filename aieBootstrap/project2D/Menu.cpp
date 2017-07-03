#include "Menu.h"
#include "StateMachine.h"
#include "Input.h"
#include <assert.h>


//---------------------------------------------------------------------------------------
Menu::Menu()
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Creates all sprites for the Menu state 
	//And asserts to ensure they are created successfully
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m_pMenu = new Texture("./textures/Menu.png");
	assert(m_pMenu);
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
Menu::~Menu()
{
	delete m_pMenu;
}

//---------------------------------------------------------------------------------------
void Menu::OnEnter()
{//LEFT EMPTY
}

//---------------------------------------------------------------------------------------
void Menu::OnUpdate(float fDeltaTime, StateMachine * State)
{
	Input* input = Input::getInstance();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Timer For sprites
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	x += fDeltaTime / 1.5;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Once 3 seconds has elapsed, the state will change to Game
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	time += fDeltaTime;
	if (time >= 3)
		State->PushState(3);
}

//---------------------------------------------------------------------------------------
void Menu::OnDraw(Renderer2D * m_2dRenderer)
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Draws sprite
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m_2dRenderer->drawSprite(m_pMenu, 650, 360);
}

//---------------------------------------------------------------------------------------
void Menu::OnExit()
{//LEFT EMPTY
}
