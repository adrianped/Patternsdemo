#include "Singleton.h"


Singleton* Singleton::ptrInstance = nullptr;

Singleton::Singleton()
{
	quitGame = false;
}


Singleton::~Singleton()
{
}

Singleton * Singleton::instance()
{
	if (!ptrInstance)
	{
		ptrInstance = new Singleton;
	}
	return ptrInstance;
}

void Singleton::gameQuit()
{
	quitGame = true;
}

bool Singleton::getQuit()
{
	return quitGame;
}
