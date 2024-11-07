#include "KingsTable.hpp"

#ifdef _WIN32
int main();
#include "windows.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    return main();
}

#endif
unsigned int recalc_square(unsigned int s_width, unsigned int s_height)
{
	if (s_width < s_height)
	{
		return s_width / 11;
	}
	else
		return s_height / 11;
}


int main()
{
    sf::RenderWindow window({1000u, 1000u}, "King's Table");
	unsigned int s_width {1000};
	unsigned int s_height {1000};
	Map gameMap(&window);
	window.setFramerateLimit(144);
	
	
	bool pieceSelected {false};
	
				

	
	int sel_x {-1};
	int sel_y {-1};
    while (window.isOpen())
    {
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
			switch (event.type)
			{
				case sf::Event::Closed:
				{
            	    window.close();
					break;
        	    }
				case sf::Event::Resized:
				{
					s_width = event.size.width;
					s_height = event.size.height;
					gameMap.setSquareSize(recalc_square(s_width, s_height));
					//this overrides aspect ratio
					window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
				}
				case sf::Event::MouseButtonPressed:
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						if (gameMap.gameOver)
							break;
						if (!pieceSelected)
							pieceSelected = gameMap.highlightSquare(event.mouseButton.x, event.mouseButton.y, sel_x, sel_y);
						else if (pieceSelected)
							pieceSelected = gameMap.tryMove(event.mouseButton.x, event.mouseButton.y, sel_x, sel_y);
					}
					else if (event.mouseButton.button == sf::Mouse::Right)
					{
						pieceSelected = gameMap.unhighlightSquare(sel_x, sel_y);
					}
				}
				case sf::Event::KeyPressed:
				{
					if (event.key.code == sf::Keyboard::Y && gameMap.gameOver)
						gameMap.resetBoard(sel_x, sel_y, pieceSelected); 
					else if (event.key.code == sf::Keyboard::N && gameMap.gameOver)
						exit(0);
				}
				default:
					break;
			}
        }
        window.clear(sf::Color::White);
		gameMap.drawBoard(sel_x, sel_y, pieceSelected);
		gameMap.drawPieces();
		window.draw(gameMap.text);
        window.display();
    }
}
