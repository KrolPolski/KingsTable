/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:03:10 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/07 14:00:25 by rboudwin         ###   ########.fr       */
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
	unsigned int square_size {90};
	sf::Font font;
	enum whoseTurn turn {Attacker};
	
public:
	sf::Text text;
	bool gameOver {false};
	Map(sf::RenderWindow *window);
	bool checkDefenderVictory(int x, int y);
	bool checkAttackerVictory(int x, int y);
	void setSquareSize(unsigned int sq_size);
	unsigned int getSquareSize();
	void checkCapture(int x, int y);
	bool checkValidPath(int tar_x, int tar_y, int& sel_x, int &sel_y) const;
	void drawBoard(int sel_x, int sel_y, bool pieceSelected);
	void drawPieces();
	void resetBoard(int& sel_x, int& sel_y, bool& pieceSelected);
	bool tryMove(int x, int y, int& sel_x, int& sel_y);
	bool highlightSquare(int x, int y, int& sel_x, int& sel_y);
	void highlightLegalMoves(int x, int y);
	bool unhighlightSquare(int& sel_x, int& sel_y);
	~Map();
};


