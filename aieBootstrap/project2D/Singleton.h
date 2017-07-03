#pragma once
class Singleton
{
public:
	Singleton();
	~Singleton();
	static Singleton* ptrInstance;

public:
	static Singleton* instance();
	void gameQuit();
	bool getQuit();
private:
	bool quitGame;
};

