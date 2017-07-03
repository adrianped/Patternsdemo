#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Loading.h"
#include "Game.h"
#include "Splash.h"
#include "Menu.h"
#include "Pausemenu.h"
#include "Singleton.h"
#include <assert.h>

using namespace aie;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Asserts to ensure they are created successfully
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m_2dRenderer = new Renderer2D();
	assert(m_2dRenderer);

	m_font = new Font("./font/consolas.ttf", 32);
	assert(m_font);
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Adding states to statemachine
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m_pStates = new StateMachine();
	m_pStates->AddState(new Splash(), 0);
	m_pStates->AddState(new Loading(), 1);
	m_pStates->AddState(new Menu(), 2);
	m_pStates->AddState(new Game(), 3);
	m_pStates->AddState(new Pausemenu(), 4);

	m_pStates->PushState(0);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	delete m_pStates;
	delete m_font;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) 
{
	m_pStates->Update(deltaTime);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Checks if the program needs to be exited
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (Singleton::instance()->getQuit())
		quit();
}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();
	
	m_pStates->Draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}