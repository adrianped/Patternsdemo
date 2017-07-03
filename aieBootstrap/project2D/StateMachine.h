#pragma once
#include "Renderer2D.h"
#include "Stack.h"
#include "BaseState.h"

using namespace aie;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update(float fDeltaTime);
	void Draw(Renderer2D* m_2dRenderer);
	void PushState(int StateId);
	void PopState();
	void AddState(BaseState* State, int StateId);

private:
	Stack<BaseState*> m_Stack;
	dynamicArray<BaseState*>  m_baseState;
};

