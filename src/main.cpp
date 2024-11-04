#include "KingsTable.hpp"

int main()
{
    auto window = sf::RenderWindow({1920u, 1080u}, "King's Table");
    window.setFramerateLimit(144);
	Map gameMap(&window);
    while (window.isOpen())
    {
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color::White);
		gameMap.drawBoard();
		gameMap.drawPieces();
        window.display();
    }
}
