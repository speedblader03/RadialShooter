#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "RadialShooter", sf::Style::Close | sf::Style::Titlebar);
    sf::Texture bossGuyTexture;
    bossGuyTexture.loadFromFile("resources/sprites/testBaddie_spr_0.png");
    sf::Sprite bossGuySprite(bossGuyTexture);
    bossGuySprite.setPosition(window.getSize().x/2-64, window.getSize().y/2-64);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(bossGuySprite);

        // end the current frame
        window.display();
    }

    return 0;
}
