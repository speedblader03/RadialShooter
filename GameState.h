#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <SFML/Graphics.hpp>

class GameState
{
public:
	GameState()
	{
	}

	//load stuff (textures, etc), initialize things
	virtual void Init(sf::RenderWindow* rw) = 0;
	//get rid of things in memory, unload things
	virtual void Cleanup() = 0;

	//not sure how these are handled
	//void Pause();
	//void Resume();

	//handle events I guess
	virtual void HandleEvents(sf::RenderWindow* rw) = 0;
	//update all gameobjects
	virtual void Update(sf::RenderWindow* rw, double tickrate) = 0;
	//draw all gameobjects
	virtual void Render(sf::RenderWindow* rw) = 0;

	virtual ~GameState()
	{
	}

	//void ChangeState(GameState* state)
};

#endif
