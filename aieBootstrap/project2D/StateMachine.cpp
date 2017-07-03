#include "StateMachine.h"
#include "Stack.h"
#include "DynamicArray.h"
#include "BaseState.h"


StateMachine::StateMachine(){}
StateMachine::~StateMachine(){}
//---------------------------------------------------------------------------------------
void StateMachine::Update(float fDeltaTime)
{
	if (m_Stack.size() > 0)
	m_Stack.top()->OnUpdate(fDeltaTime, this);
}
//---------------------------------------------------------------------------------------
void StateMachine::Draw(Renderer2D * m_2dRenderer)
{	
	if (m_Stack.size() > 4)
		m_Stack.secondTop()->OnDraw(m_2dRenderer);

	if (m_Stack.size() > 0)
		m_Stack.top()->OnDraw(m_2dRenderer);
}

//---------------------------------------------------------------------------------------
void StateMachine::PushState(int StateId)
{
	m_Stack.push(m_baseState[StateId]);
}
//---------------------------------------------------------------------------------------
void StateMachine::PopState()
{
	m_Stack.pop();
}
//---------------------------------------------------------------------------------------
void StateMachine::AddState(BaseState * State, int StateId)
{
	m_baseState.Insert(StateId, State);
}
