/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Defender.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:40:45 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/04 16:10:26 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "KingsTable.hpp"
#include "Piece.hpp"

class Defender : Piece
{
private:
	/* data */
public:
	Defender(/* args */);
	virtual int Move(int x, int y) override;
	~Defender();
};

