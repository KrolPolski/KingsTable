/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Piece.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:37:26 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/04 16:13:35 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Piece
{
protected:
	int			x;
	int	 		y;
	bool		alive;
	std::string	texture;
public:
	Piece();
	int virtual Move(int x, int y) = 0;
	virtual ~Piece();
};


