#include <SFML/Graphics.hpp>
#include <vector>

#include "PlayState.h"

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "RadialShooter",
			sf::Style::Close | sf::Style::Titlebar);

	sf::Clock gameClock;

	const double tickRate = 1.0f / 60.0f;

	double currentTime = gameClock.getElapsedTime().asSeconds();
	double accumulator = 0.0;

	PlayState playState;
	playState.Init(&window);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		playState.HandleEvents(&window);

		double newTime = gameClock.getElapsedTime().asSeconds();
		double frameTime = newTime - currentTime;
		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= tickRate)
		{
			playState.Update(&window, tickRate);
			accumulator -= tickRate;
		}

		playState.Render(&window);
	}
	return 0;
}
