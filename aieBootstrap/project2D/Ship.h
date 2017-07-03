#pragma once
#include "Entity.h"
#include "Renderer2D.h"

using namespace aie;

class Ship : public Entity
{
public:
	Ship();
	~Ship();
	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);

private:
	Texture* m_Ship;
};

