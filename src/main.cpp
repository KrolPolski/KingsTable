#include "KingsTable.hpp"

unsigned int recalc_square(unsigned int s_width, unsigned int s_height)
{
	if (s_width < s_height)
	{
		return s_height / 10;
	}
	else
		return s_width / 10;
}
int main()
{
	//Not sure why I had to change this, but it wouldn't compile it without doing it today.
    //auto window = sf::RenderWindow({1920u, 1080u}, "King's Table");
    sf::RenderWindow window({1000u, 1000u}, "King's Table");
	unsigned int s_width {1000};
	unsigned int s_height {1000};
	unsigned int square_size {100};
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
				case sf::Event::Resized:
				{
					s_width = event.size.width;
					s_height = event.size.height;
					square_size = recalc_square(s_width, s_height);
					std::cout << "new width: " << event.size.width << std::endl;
					std::cout << "new height: " << event.size.height << std::endl;
				}
				case sf::Event::MouseButtonPressed:
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						if (!pieceSelected)
							pieceSelected = gameMap.highlightSquare(event.mouseButton.x, event.mouseButton.y, sel_x, sel_y, turn);
						else if (pieceSelected)
							pieceSelected = gameMap.tryMove(event.mouseButton.x, event.mouseButton.y, sel_x, sel_y, turn);
						if (!pieceSelected)
							pieceSelected = gameMap.unhighlightSquare(sel_x, sel_y);
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
		gameMap.drawBoard(sel_x, sel_y, pieceSelected, square_size);
		gameMap.drawPieces(square_size);
        window.display();
    }
}
