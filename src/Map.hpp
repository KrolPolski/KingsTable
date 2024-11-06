/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:03:10 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/06 12:26:12 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Map
{
private:
	char init_map[9][9]
	{
		{'C', '0', '0', 'A', 'A', 'A', '0', '0', 'C'},
		{'0', '0', '0', '0', 'A', '0', '0', '0', '0'},
		{'0', '0', '0', '0', 'D', '0', '0', '0', '0'},
		{'A', '0', '0', '0', 'D', '0', '0', '0', 'A'},
		{'A', 'A', 'D', 'D', 'K', 'D', 'D', 'A', 'A'},
		{'A', '0', '0', '0', 'D', '0', '0', '0', 'A'},
		{'0', '0', '0', '0', 'D', '0', '0', '0', '0'},
		{'0', '0', '0', '0', 'A', '0', '0', '0', '0'},
		{'C', '0', '0', 'A', 'A', 'A', '0', '0', 'C'}
	};
	char curr_map[9][9]
	{
		{'C', '0', '0', 'A', 'A', 'A', '0', '0', 'C'},
		{'0', '0', '0', '0', 'A', '0', '0', '0', '0'},
		{'0', '0', '0', '0', 'D', '0', '0', '0', '0'},
		{'A', '0', '0', '0', 'D', '0', '0', '0', 'A'},
		{'A', 'A', 'D', 'D', 'K', 'D', 'D', 'A', 'A'},
		{'A', '0', '0', '0', 'D', '0', '0', '0', 'A'},
		{'0', '0', '0', '0', 'D', '0', '0', '0', '0'},
		{'0', '0', '0', '0', 'A', '0', '0', '0', '0'},
		{'C', '0', '0', 'A', 'A', 'A', '0', '0', 'C'}
	};
	sf::RectangleShape mapSquares[9][9];
	sf::RenderWindow *mapWindow;
public:
	Map(sf::RenderWindow *window);
	bool checkDefenderVictory(int x, int y);
	bool checkAttackerVictory(int x, int y);
	void checkCapture(int x, int y);
	bool checkValidPath(int tar_x, int tar_y, int& sel_x, int &sel_y) const;
	void drawBoard(int sel_x, int sel_y, bool pieceSelected, unsigned int square_size);
	void drawPieces(unsigned int square_size);
	bool tryMove(int x, int y, int& sel_x, int& sel_y, enum whoseTurn& turn);
	bool highlightSquare(int x, int y, int& sel_x, int& sel_y, enum whoseTurn& turn);
	void highlightLegalMoves(int x, int y);
	bool unhighlightSquare(int& sel_x, int& sel_y);
	~Map();
};


