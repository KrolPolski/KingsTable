#include "KingsTable.hpp"

int main()
{
	//Not sure why I had to change this, but it wouldn't compile it without doing it today.
    //auto window = sf::RenderWindow({1920u, 1080u}, "King's Table");
    sf::RenderWindow window({1920u, 1080u}, "King's Table");
	window.setFramerateLimit(144);
	Map gameMap(&window);
	bool pieceSelected {false};
	

	enum whoseTurn turn = Attacker;
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
				case sf::Event::MouseButtonPressed:
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						if (!pieceSelected)
							pieceSelected = gameMap.highlightSquare(event.mouseButton.x, event.mouseButton.y, sel_x, sel_y, turn);
						else if (pieceSelected)
							pieceSelected = gameMap.tryMove(event.mouseButton.x, event.mouseButton.y, sel_x, sel_y, turn);
					}
					else if (event.mouseButton.button == sf::Mouse::Right)
					{
						pieceSelected = gameMap.unhighlightSquare(sel_x, sel_y);
					}
				}
				default:
					break;
			}
        }
        window.clear(sf::Color::White);
		gameMap.drawBoard();
		gameMap.drawPieces();
        window.display();
    }
}
