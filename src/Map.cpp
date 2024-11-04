/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:12:44 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/04 16:48:05 by rboudwin         ###   ########.fr       */
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
				mapSquares[i][k].setFillColor(sf::Color(101, 67, 33));
			else if (init_map[i][k] == 'D')
				mapSquares[i][k].setFillColor(sf::Color(255, 255, 50));
			else if (init_map[i][k] == 'K')
				mapSquares[i][k].setFillColor(sf::Color(255, 215, 0));
			else if (init_map[i][k] == '0')
				mapSquares[i][k].setFillColor(sf::Color(201, 167, 133));
			else if (init_map[i][k] == 'C')
				mapSquares[i][k].setFillColor(sf::Color(255, 200, 0));
			if (curr_map[i][k] == 'a' || curr_map[i][k] == 'd' || curr_map[i][k] == 'k')
				mapSquares[i][k].setOutlineColor(sf::Color(255,0,0));
			else
				mapSquares[i][k].setOutlineColor(sf::Color(0,0,0));
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
				attackers[attackerIndex].setFillColor(sf::Color(0, 0, 0));
				attackers[attackerIndex].setOutlineColor(sf::Color(200,200,200));
				attackers[attackerIndex].setOutlineThickness(2);
				attackers[attackerIndex].setPosition(58 + k * 100, 58 + i * 100); //50 for edge of board, 8 to center pieces based on the square outlines being 4 on each side
				mapWindow->draw(attackers[attackerIndex]);
				attackerIndex++;	
			}
			else if (curr_map[i][k] == 'D' || curr_map[i][k] == 'd')
			{
				defenders[defenderIndex].setRadius(40);
				defenders[defenderIndex].setPointCount(5);
				defenders[defenderIndex].setFillColor(sf::Color(255,255,255));
				defenders[defenderIndex].setOutlineColor(sf::Color(50,50,50));
				defenders[defenderIndex].setOutlineThickness(2);	
				defenders[defenderIndex].setPosition(58 + k * 100, 58 + i * 100);	
				mapWindow->draw(defenders[defenderIndex]);
				defenderIndex++;
			}
			else if (curr_map[i][k] == 'K' || curr_map[i][k] == 'k')
			{
				myLiege.setFillColor(sf::Color(255, 245, 30));
				myLiege.setOutlineColor(sf::Color(50, 50, 50));
				myLiege.setOutlineThickness(2);
				myLiege.setPosition(58 + k * 100, 58 + i * 100);
				mapWindow->draw(myLiege);
			}
			
		}
	}
}

void Map::highlightLegalMoves(int x, int y)
{
	//add visual indicators later	
}

bool Map::highlightSquare(int x, int y, int& sel_x, int& sel_y)
{
	int map_x {(x - 50) / 100};
	int map_y {(y - 50) / 100};
	
	if (map_x > 8 || map_y > 8 || curr_map[map_y][map_x] == '0')
		return 0;
	curr_map[map_y][map_x] = std::tolower(curr_map[map_y][map_x]);
	highlightLegalMoves(map_x, map_y);
	sel_x = map_x;
	sel_y = map_y;
	return 1;
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

bool Map::tryMove(int x, int y, int& sel_x, int& sel_y)
{
	int map_x {(x - 50) / 100};
	int map_y {(y - 50) / 100};
	
	if (sel_x < 0 || sel_y < 0 || map_x > 8 || map_y > 8)
		return (1);
	if ((map_x == sel_x || map_y == sel_y) && (curr_map[map_y][map_x] == '0' || curr_map[map_y][map_x] == 'C'))
	{
		std::cout << "Move is legal, executing" << std::endl;
		curr_map[map_y][map_x] = std::toupper(curr_map[sel_y][sel_x]);
		if (init_map[map_y][map_x] == 'C')
			curr_map[sel_y][sel_x] = 'C';
		else
			curr_map[sel_y][sel_x] = '0';
		//unhighlightSquare(sel_x, sel_y);
		return (0);
	}
	else 
	{
		std::cout << "Illegal move" << std::endl;
		return (1);
	}
	
}