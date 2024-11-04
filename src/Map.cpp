/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:12:44 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/04 15:00:44 by rboudwin         ###   ########.fr       */
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
	int attackerIndex {0};
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t k = 0; k < 9; k++)
		{
			if (curr_map[i][k] == 'A')
			{
				attackers[attackerIndex].setRadius(40);
				attackers[attackerIndex].setFillColor(sf::Color(0, 0, 0));
				attackers[attackerIndex].setOutlineColor(sf::Color(200,200,200));
				attackers[attackerIndex].setOutlineThickness(2);
				attackers[attackerIndex].setPosition(58 + k * 100, 58 + i * 100);
				mapWindow->draw(attackers[attackerIndex]);
				attackerIndex++;	
			}
		}
	}
}