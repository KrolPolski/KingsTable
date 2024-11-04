/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawBoard.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:38:43 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/04 14:12:16 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "KingsTable.hpp"

int	drawBoard(sf::RenderWindow& window, Map& gameMap)
{
	//sf::RectangleShape defenderSquare(sf::Vector2f(120.f, 120.f));
	//defenderSquare.setFillColor(sf::Color(101, 67, 33));
	
	sf::RectangleShape defSquares[8];
	
	for (size_t i = 0; i < 8; i++)
	{
		defSquares[i].setSize(sf::Vector2f(100, 100));
		defSquares[i].setFillColor(sf::Color(101, 67, 33));
		defSquares[i].setOutlineColor(sf::Color(0,0,0));
		defSquares[i].setOutlineThickness(4);
		defSquares[i].setPosition(550, 50 + (i * 100));
		window.draw(defSquares[i]);
	}
	
	//defenderSquare.setPosition(50, 50);
	//sf::RectangleShape defenderSquare2(defenderSquare);
	//defenderSquare2.setPosition(150, 150);
	//window.draw(defenderSquare);
	//window.draw(defenderSquare2);
	//window.
	return 0;
}