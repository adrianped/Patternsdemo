#include "Game.h"
#include "Input.h"
#include <assert.h>
#include "StateMachine.h"
#include "Singleton.h"
#include <assert.h>

//---------------------------------------------------------------------------------------
Game::Game()
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Creates all sprites for the game state 
	//And asserts to ensure they are created successfully
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m_pGame = new Texture("./textures/Game.png");
	assert(m_pGame);
	m_pOptions = new Texture("./textures/Options.png");
	assert(m_pOptions);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Times how long you are in the state for
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	time = 0;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Variable to set the timer for the sprites
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	x = 0;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Player positions and speed
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	playerX = 650;
	playerY = 360;
	m_speed = 1000;
}

//---------------------------------------------------------------------------------------
Game::~Game()
{
	delete m_pGame;
}

//---------------------------------------------------------------------------------------
void Game::OnEnter()
{//LEFT EMPTY
}

//---------------------------------------------------------------------------------------
void Game::OnUpdate(float fDeltaTime, StateMachine * State)
{
	Input* input = Input::getInstance();
	time += fDeltaTime;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Use W,A,S,D keys to move Sprite
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	if (input->isKeyDown(INPUT_KEY_W))
		playerY += m_speed * 2 * fDeltaTime;

	if (input->isKeyDown(INPUT_KEY_S))
		playerY -= m_speed * fDeltaTime;

	if (input->isKeyDown(INPUT_KEY_A))
		playerX -= m_speed * fDeltaTime;

	if (input->isKeyDown(INPUT_KEY_D))
		playerX += m_speed * 2 * fDeltaTime;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Change to PauseMenu state
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (input->isKeyDown(INPUT_KEY_ESCAPE))
		State->PushState(4);

}

//---------------------------------------------------------------------------------------
void Game::OnDraw(Renderer2D * m_2dRenderer)
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Draws sprites
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m_2dRenderer->drawSprite(m_pGame, playerX, playerY);
	m_2dRenderer->drawSprite(m_pOptions, 100, 50);
}

//---------------------------------------------------------------------------------------
void Game::OnExit()
{//LEFT EMPTY
}
