/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:12:44 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/06 11:18:50 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "KingsTable.hpp"
#include "Map.hpp"

Map::Map(sf::RenderWindow *window)
{
	mapWindow = window;
}

// Map::Map()
// {
// }

Map::~Map()
{
}

void Map::drawBoard()
{
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t k = 0; k < 9; k++)
		{
			mapSquares[i][k].setSize(sf::Vector2f(100, 100));
			if (init_map[i][k] == 'A')
				mapSquares[i][k].setFillColor(sf::Color(117, 106, 94));
			else if (init_map[i][k] == 'D')
				mapSquares[i][k].setFillColor(sf::Color(181, 170, 158));
			else if (init_map[i][k] == 'K')
				mapSquares[i][k].setFillColor(sf::Color(178, 130, 107));
			else if (init_map[i][k] == '0')
				mapSquares[i][k].setFillColor(sf::Color(149, 138, 126));
			else if (init_map[i][k] == 'C')
				mapSquares[i][k].setFillColor(sf::Color(217, 230, 234));
			if (curr_map[i][k] == 'a' || curr_map[i][k] == 'd' || curr_map[i][k] == 'k')
				mapSquares[i][k].setOutlineColor(sf::Color(255,0,0));
			else
				mapSquares[i][k].setOutlineColor(sf::Color(51, 0, 6));
			mapSquares[i][k].setOutlineThickness(4);
			mapSquares[i][k].setPosition(50 + (k * 100), 50 + (i * 100));
			mapWindow->draw(mapSquares[i][k]);
		}
	}
}
void Map::drawPieces()
{
	std::vector<sf::CircleShape> attackers(16);
	std::vector<sf::CircleShape> defenders(8);
	sf::CircleShape myLiege(40, 6);
	int attackerIndex {0};
	int defenderIndex {0};
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t k = 0; k < 9; k++)
		{
			if (curr_map[i][k] == 'A' || curr_map[i][k] == 'a')
			{
				attackers[attackerIndex].setRadius(40);
				attackers[attackerIndex].setFillColor(sf::Color(149, 200, 219));
				attackers[attackerIndex].setOutlineColor(sf::Color(51, 0, 6));
				attackers[attackerIndex].setOutlineThickness(5);
				attackers[attackerIndex].setPosition(58 + k * 100, 58 + i * 100); //50 for edge of board, 8 to center pieces based on the square outlines being 4 on each side
				mapWindow->draw(attackers[attackerIndex]);
				attackerIndex++;	
			}
			else if (curr_map[i][k] == 'D' || curr_map[i][k] == 'd')
			{
				defenders[defenderIndex].setRadius(40);
				defenders[defenderIndex].setPointCount(5);
				defenders[defenderIndex].setFillColor(sf::Color(255, 220, 143));
				defenders[defenderIndex].setOutlineColor(sf::Color(51, 0, 6));
				defenders[defenderIndex].setOutlineThickness(5);	
				defenders[defenderIndex].setPosition(58 + k * 100, 58 + i * 100);	
				mapWindow->draw(defenders[defenderIndex]);
				defenderIndex++;
			}
			else if (curr_map[i][k] == 'K' || curr_map[i][k] == 'k')
			{
				myLiege.setFillColor(sf::Color(244, 101, 71));
				myLiege.setOutlineColor(sf::Color(51, 0, 6));
				myLiege.setOutlineThickness(5);
				myLiege.setPosition(58 + k * 100, 58 + i * 100);
				mapWindow->draw(myLiege);
			}
			
		}
	}
}

bool Map::checkValidPath(int tar_x, int tar_y, int& sel_x, int &sel_y) const
{
	//vertical case
	if (tar_x == sel_x)
	{
		if (tar_y > sel_y)
		{
			while (tar_y > sel_y)
			{
				if (curr_map[tar_y][tar_x] != '0' && curr_map[tar_y][tar_x] != 'C')
					return false;
				tar_y--;
			}
			return true;
		}
		else if (tar_y < sel_y)
		{
			while (tar_y < sel_y)
			{
				if (curr_map[tar_y][tar_x] != '0' && curr_map[tar_y][tar_x] != 'C')
					return false;
				tar_y++;
			}
			return true;
		}
		else
			return false;
	}
	//horizontal case
	else if (tar_y == sel_y)
	{
		if (tar_x > sel_x)
		{
			while (tar_x > sel_x)
			{
				if (curr_map[tar_y][tar_x] != '0' && curr_map[tar_y][tar_x] != 'C')
					return false;
				tar_x--;
			}
			return true;
		}
		else if (tar_x < sel_x)
		{
			while (tar_x < sel_x)
			{
				if (curr_map[tar_y][tar_x] != '0' && curr_map[tar_y][tar_x] != 'C')
					return false;
				tar_x++;	
			}
			return true;
		}
		else return false;
	}	
	else
	{
		std::cout << "Something went wront in checkValidPath" << std::endl;
		return false;
	}
}

void Map::highlightLegalMoves(int x, int y)
{
	//add visual indicators later	
}

bool Map::highlightSquare(int x, int y, int& sel_x, int& sel_y, enum whoseTurn& turn)
{
	int map_x {(x - 50) / 100};
	int map_y {(y - 50) / 100};
	
	if (map_x > 8 || map_y > 8 || curr_map[map_y][map_x] == '0')
		return false;
	
	if ((turn == Attacker && curr_map[map_y][map_x] == 'A') || (turn == Defender && (curr_map[map_y][map_x] == 'D' || curr_map[map_y][map_x] == 'K'))) 
		curr_map[map_y][map_x] = std::tolower(curr_map[map_y][map_x]);
	{
		highlightLegalMoves(map_x, map_y);
		sel_x = map_x;
		sel_y = map_y;
		return true;
	}
	return false;
	//std::cout << "Now we have a " << curr_map[map_y][map_x] << " at " << map_y << ":" << map_x << std::endl;
	//mapWindow->draw(mapSquares[map_y][map_x]);
}
bool Map::unhighlightSquare(int& sel_x, int& sel_y)
{
	if (sel_x < 0 || sel_y < 0 || sel_x > 8 || sel_y > 8)
		{
			sel_x = -1;
			sel_y = -1;
			return 0;
		}
	curr_map[sel_y][sel_x] = std::toupper(curr_map[sel_y][sel_x]);
	sel_x = -1;
	sel_y = -1;
	return (0);
	//std::cout << "Now we have a " << curr_map[map_y][map_x] << " at " << map_y << ":" << map_x << std::endl;
	//mapWindow->draw(mapSquares[map_y][map_x]);
}

bool Map::checkDefenderVictory(int x, int y)
{
	if (x >= 0 && y >= 0 && x < 9 && y < 9)
	{
		if (curr_map[y][x] == 'K' || curr_map[y][x] == 'k')
		{
			if (init_map[y][x] == 'C')
			{
				std::cout << "Defender wins! Long live the King!" << std::endl;
				exit(0);
			}
		}
		return false;
	}
	return false;
}

// pass this the king location after an attacker move.
bool Map::checkAttackerVictory(int x, int y)
{
	//Find King
	int i = 0;
	int k = 0;

	while (i < 9)
	{
		while (k < 9)
		{
			if (curr_map[i][k] == 'K' || curr_map[i][k] == 'k')
			{
				x = k;
				y = i;
				break;
			}
			k++;
		}
		k = 0;
		i++;
	}
	//check if King is surrounded
			bool kingSurrounded = false;
			if (x == 0)
			{
				if ((curr_map[y][x + 1] == 'A' || curr_map[y][x + 1] == 'a')
					&& (curr_map[y + 1][x] == 'A' || curr_map[y + 1][x] == 'a')
					&& (curr_map[y - 1][x] == 'A' || curr_map[y-1][x] == 'a'))
					kingSurrounded = true;
			}
			else if (x == 8)
			{
				if ((curr_map[y][x - 1] == 'A' || curr_map[y][x - 1] == 'a')
					&& (curr_map[y + 1][x] == 'A' || curr_map[y + 1][x] == 'a')
					&& (curr_map[y - 1][x] == 'A' || curr_map[y-1][x] == 'a'))
					kingSurrounded = true;
			}
			else if (y == 0)
			{
				if ((curr_map[y][x - 1] == 'A' || curr_map[y][x - 1] == 'a')
					&& (curr_map[y][x + 1] == 'A' || curr_map[y][x + 1] == 'a')
					&& (curr_map[y + 1][x] == 'A' || curr_map[y + 1][x] == 'a'))
					kingSurrounded = true;
			}
			else if (y == 8)
			{
				if ((curr_map[y][x - 1] == 'A' || curr_map[y][x - 1] == 'a')
					&& (curr_map[y][x + 1] == 'A' || curr_map[y][x + 1] == 'a')
					&& (curr_map[y - 1][x] == 'A' || curr_map[y-1][x] == 'a'))
					kingSurrounded = true;
			}
			else
			{
				if ((curr_map[y][x - 1] == 'A' || curr_map[y][x - 1] == 'a')
					&& (curr_map[y][x + 1] == 'A' || curr_map[y][x + 1] == 'a')
					&& (curr_map[y - 1][x] == 'A' || curr_map[y-1][x] == 'a')
					&& (curr_map[y + 1][x] == 'A' || curr_map[y + 1][x] == 'a'))
					kingSurrounded = true;
			}
			if (kingSurrounded)
			{
				std::cout << "The attackers have overthrown the king and win the game." << std::endl;
				exit(0);
			}
			else
				return (kingSurrounded);
}

void Map::checkCapture(int x, int y)
{
	if (x > 8 || x < 0 || y > 8 || y < 0)
		return ;
	
	std::cout << "We must have valid inputs for checkCapture" << std::endl;

	//attacker moved
	if (curr_map[y][x] == 'A' || curr_map[y][x] == 'a')
	{
		//check left
		if (x > 1 && (curr_map[y][x - 1] == 'D' || curr_map[y][x - 1] == 'd')
			&& (curr_map[y][x - 2] == 'A' || curr_map[y][x - 2] == 'a'))
			{
				std::cout << "Capturing to the left" << std::endl;
				curr_map[y][x - 1] = '0';
			}
		//check right
		if (x < 7 && (curr_map[y][x + 1] == 'D' || curr_map[y][x + 1] == 'd')
			&& (curr_map[y][x+2] == 'A' || curr_map[y][x+2] == 'a'))
			{
				std::cout << "Capturing to the right" << std::endl;
				curr_map[y][x + 1] = '0';
			}
		//look up
		if (y > 1 && (curr_map[y - 1][x] == 'D' || curr_map[y - 1][x] == 'd')
			&& (curr_map[y-2][x] == 'A' || curr_map[y-2][x] == 'a'))
			{
				std::cout << "Capturing up" << std::endl;
				curr_map[y-1][x] = '0';
			}
		//look down
		if (y < 7 && (curr_map[y + 1][x] == 'D' || curr_map[y + 1][x] == 'd')
			&& (curr_map[y + 2][x] == 'A' || curr_map[y + 2][x] == 'a'))
			{
				std::cout << "Capturing down" << std::endl;
				curr_map[y + 1][x] = '0';
			}
		//corner cases
		if (((y == 1 && x == 0) && (curr_map[0][1] == 'A' || curr_map[0][1] == 'a'))
			|| ((y == 0 && x == 1) && (curr_map[1][0] == 'A' || curr_map[1][0] == 'a'))
			&& (curr_map[0][0] == 'D' || curr_map[0][0] == 'd')) 
		{
				std::cout << "Northwest corner captured" << std::endl;
				curr_map[0][0] = 'C';
		}
		if (((y == 1 && x == 8) && (curr_map[0][7] == 'A' || curr_map[0][7] == 'a'))
			|| ((y == 0 && x == 7) && (curr_map[1][8] == 'A' || curr_map[1][8] == 'a'))
			&& (curr_map[0][8] == 'D' || curr_map[0][8] == 'd')) 
		{
				std::cout << "Northeast corner captured" << std::endl;
				curr_map[0][8] = 'C';
		}
		if (((y == 8 && x == 7) && (curr_map[7][8] == 'A' || curr_map[7][8] == 'a'))
			|| ((y == 7 && x == 8) && (curr_map[8][7] == 'A' || curr_map[8][7] == 'a'))
			&& (curr_map[8][8] == 'D' || curr_map[8][8] == 'd')) 
		{
				std::cout << "Southeast corner captured" << std::endl;
				curr_map[8][8] = 'C';
		}
		if (((y == 8 && x == 1) && (curr_map[7][0] == 'A' || curr_map[7][0] == 'a'))
			|| ((y == 7 && x == 0) && (curr_map[8][1] == 'A' || curr_map[8][1] == 'a'))
			&& (curr_map[8][0] == 'D' || curr_map[8][0] == 'd')) 
		{
				std::cout << "Southwest corner captured" << std::endl;
				curr_map[8][0] = 'C';
		}
		
	}
	else if (curr_map[y][x] == 'D' || curr_map[y][x] == 'd' || curr_map[y][x] == 'K' || curr_map[y][x] == 'k')
	{
		//check left
		if (x > 1 && (curr_map[y][x - 1] == 'A' || curr_map[y][x - 1] == 'a')
			&& (curr_map[y][x - 2] == 'D' || curr_map[y][x - 2] == 'd' || curr_map[y][x - 2] == 'K' || curr_map[y][x-2] == 'k'))
			{
				std::cout << "Capturing to the left" << std::endl;
				curr_map[y][x - 1] = '0';
			}
		//check right
		if (x < 7 && (curr_map[y][x + 1] == 'A' || curr_map[y][x + 1] == 'a')
			&& (curr_map[y][x+2] == 'D' || curr_map[y][x+2] == 'D' || curr_map[y][x+2] == 'K' || curr_map[y][x+2] == 'k'))
			{
				std::cout << "Capturing to the right" << std::endl;
				curr_map[y][x + 1] = '0';
			}
		//look up
		if (y > 1 && (curr_map[y - 1][x] == 'A' || curr_map[y - 1][x] == 'a')
			&& (curr_map[y-2][x] == 'D' || curr_map[y-2][x] == 'D' || curr_map[y-2][x] == 'K' || curr_map[y-2][x] == 'k'))
			{
				std::cout << "Capturing up" << std::endl;
				curr_map[y-1][x] = '0';
			}
		//look down
		if (y < 7 && (curr_map[y + 1][x] == 'A' || curr_map[y + 1][x] == 'a')
			&& (curr_map[y + 2][x] == 'D' || curr_map[y + 2][x] == 'd' || curr_map[y+2][x] == 'K' || curr_map[y+2][x] == 'k'))
			{
				std::cout << "Capturing down" << std::endl;
				curr_map[y + 1][x] = '0';
			}
		//corner cases
		if (((y == 1 && x == 0) && (curr_map[0][1] == 'D' || curr_map[0][1] == 'd' || curr_map[0][1] == 'K' || curr_map[0][1] == 'k'))
			|| ((y == 0 && x == 1) && (curr_map[1][0] == 'D' || curr_map[1][0] == 'd' || curr_map[1][0] == 'K' || curr_map[1][0] == 'k'))
			&& (curr_map[0][0] == 'A' || curr_map[0][0] == 'a')) 
		{
				std::cout << "Northwest corner captured" << std::endl;
				curr_map[0][0] = 'C';
		}
		if (((y == 1 && x == 8) && (curr_map[0][7] == 'D' || curr_map[0][7] == 'd' || curr_map[0][7] == 'K' || curr_map[0][7] == 'k'))
			|| ((y == 0 && x == 7) && (curr_map[1][8] == 'D' || curr_map[1][8] == 'd' || curr_map[1][8] == 'K' || curr_map[1][8] == 'k'))
			&& (curr_map[0][8] == 'A' || curr_map[0][8] == 'a')) 
		{
				std::cout << "Northeast corner captured" << std::endl;
				curr_map[0][8] = 'C';
		}
		if (((y == 8 && x == 7) && (curr_map[7][8] == 'D' || curr_map[7][8] == 'd' || curr_map[7][8] == 'K' || curr_map[7][8] == 'k'))
			|| ((y == 7 && x == 8) && (curr_map[8][7] == 'D' || curr_map[8][7] == 'd' || curr_map[8][7] == 'K' || curr_map[8][7] == 'k'))
			&& (curr_map[8][8] == 'A' || curr_map[8][8] == 'a')) 
		{
				std::cout << "Southeast corner captured" << std::endl;
				curr_map[8][8] = 'C';
		}
		if (((y == 8 && x == 1) && (curr_map[7][0] == 'D' || curr_map[7][0] == 'd' || curr_map[7][0] == 'K' || curr_map[7][0] == 'k'))
			|| ((y == 7 && x == 0) && (curr_map[8][1] == 'D' || curr_map[8][1] == 'd' || curr_map[8][1] == 'K' || curr_map[8][1] == 'k'))
			&& (curr_map[8][0] == 'A' || curr_map[8][0] == 'a')) 
		{
				std::cout << "Southwest corner captured" << std::endl;
				curr_map[8][0] = 'C';
		}
		
	}}
	//defender moved
	/*else if (curr_map[y][x] == 'D' || curr_map[y][x] == 'd'
		|| curr_map[y][x] == 'k' || curr_map[y][x] == 'k')
	{
		
	}
	
}*/

bool Map::tryMove(int x, int y, int& sel_x, int& sel_y, enum whoseTurn& turn)
{
	int map_x {(x - 50) / 100};
	int map_y {(y - 50) / 100};
	
	if (sel_x < 0 || sel_y < 0 || sel_y > 8 || sel_x > 8 || map_x < 0 || map_y < 0 || map_x > 8 || map_y > 8)
		return (true);
	if ((curr_map[sel_y][sel_x] == 'A' || curr_map[sel_y][sel_x] == 'a' && turn == Defender)
		|| ((curr_map[sel_y][sel_x] == 'D' || curr_map[sel_y][sel_x] == 'd' || curr_map[sel_y][sel_x] == 'K' || curr_map[sel_y][sel_x] == 'k') && turn == Attacker))
		return (false);
	if (map_x == sel_x && map_y == sel_y)
	{
		unhighlightSquare(sel_x, sel_y);
		sel_x = -1;
		sel_y = -1;
		return false;
	}
	std::cout << "map_x: " << map_x << " map_y: "<< map_y << " sel_x: " << sel_x << " sel_y: " << sel_y << std::endl;
	if ((map_x == sel_x || map_y == sel_y) && (curr_map[map_y][map_x] == '0' || curr_map[map_y][map_x] == 'C'))
	{
		if (checkValidPath(map_x, map_y, sel_x, sel_y))
		{
			std::cout << "Move is legal, executing" << std::endl;
			curr_map[map_y][map_x] = std::toupper(curr_map[sel_y][sel_x]);
			if (init_map[map_y][map_x] == 'C')
				curr_map[sel_y][sel_x] = 'C';
			else
				curr_map[sel_y][sel_x] = '0';
			//unhighlightSquare(sel_x, sel_y);
			checkDefenderVictory(map_x, map_y);
			checkAttackerVictory(map_x, map_y);
			checkCapture(map_x, map_y);
			if (turn == Attacker)
			{
				std::cout << "Defender's turn now" << std::endl;
				turn = Defender;
			}
			else if (turn == Defender)
			{
				std::cout << "Attacker's turn now" << std::endl;
				turn = Attacker;
			}
				
			return (0);
		}
		else
			std::cout << "Path is blocked, illegal move" << std::endl;
			return false;
	}
	else 
	{
		std::cout << "Illegal move" << std::endl;
		return (1);
	}
	
}