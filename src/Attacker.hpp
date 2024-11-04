/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Attacker.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:42:48 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/04 10:43:20 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Piece.hpp"

class Attacker
{
private:
	/* data */
public:
	Attacker(/* args */);
	int Move(int x, int y) override;
	~Attacker();
};

Attacker::Attacker(/* args */)
{
}

Attacker::~Attacker()
{
}
