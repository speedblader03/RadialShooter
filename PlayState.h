#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_

#include "GameState.h"
#include "TestBossGuy.h"

class PlayState: public GameState
{
public:
	//PlayState();
	void Init(sf::RenderWindow* rw);
	//get rid of things in memory, unload things
	void Cleanup();

	//not sure how these are handled
	//void Pause();
	//void Resume();

	//handle events I guess
	void HandleEvents(sf::RenderWindow* rw);
	//update all gameobjects
	void Update(sf::RenderWindow* rw, double tickrate);
	//draw all gameobjects
	void Render(sf::RenderWindow* rw);

	virtual ~PlayState();

private:
	TestBossGuy bossGuy;
	sf::Texture bossGuyTexture;
};

#endif
