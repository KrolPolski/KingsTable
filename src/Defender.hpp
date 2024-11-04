/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Defender.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:40:45 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/04 10:42:04 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Piece.hpp"

class Defender : Piece
{
private:
	/* data */
public:
	Defender(/* args */);
	int Move(int x, int y) override;
	~Defender();
};

Defender::Defender(/* args */)
{
}

Defender::~Defender()
{
}
