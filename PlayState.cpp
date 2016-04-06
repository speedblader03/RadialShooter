#include "PlayState.h"

void PlayState::Init(sf::RenderWindow* rw)
{
	//gameObjects = new std::vector<GameObject>;
	bossGuyTexture.loadFromFile("resources/sprites/testBaddie_spr_0.png");

	bossGuy.setTexture(bossGuyTexture);
	bossGuy.setPosition(rw->getSize().x / 2, rw->getSize().y / 2);
}

void PlayState::Cleanup()
{

}

void PlayState::HandleEvents(sf::RenderWindow* rw)
{
	sf::Event event;
	while (rw->pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
			rw->close();
	}
}

void PlayState::Update(sf::RenderWindow* rw, double tickrate)
{
	bossGuy.Update(tickrate);
}

void PlayState::Render(sf::RenderWindow* rw)
{
	// clear the window with black color
	rw->clear(sf::Color::Black);

	// draw everything here...
	// window.draw(...);
	rw->draw(bossGuy);

	// end the current frame
	rw->display();
}

PlayState::~PlayState()
{

}
