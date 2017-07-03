#include "Pausemenu.h"
#include "Texture.h"
#include "Singleton.h"
#include "Input.h"
#include "StateMachine.h"
#include <assert.h>

//---------------------------------------------------------------------------------------
Pausemenu::Pausemenu()
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Creates all sprites for the splash state 
	//And asserts to ensure they are created successfully
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m_pPause = new Texture("./textures/Pause.png");
	assert(m_pPause);
}

//---------------------------------------------------------------------------------------
Pausemenu::~Pausemenu()
{
	delete m_pPause;
}

//---------------------------------------------------------------------------------------
void Pausemenu::OnEnter()
{//LEFT EMPTY
}

//---------------------------------------------------------------------------------------
void Pausemenu::OnUpdate(float fDeltaTime, StateMachine * State)
{
	Input* input = Input::getInstance();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//If ESC key is pressed game will exit
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (input->wasKeyPressed(INPUT_KEY_ESCAPE))
		Singleton::instance()->gameQuit();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//If ENTER is press game state will resume
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (input->isKeyDown(INPUT_KEY_ENTER))
		State->PopState();
}

//---------------------------------------------------------------------------------------
void Pausemenu::OnDraw(Renderer2D * m_2dRenderer)
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Draws sprite
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m_2dRenderer->drawSprite(m_pPause, 600, 400);
}

//---------------------------------------------------------------------------------------
void Pausemenu::OnExit()
{//LEFT EMPTY
}
