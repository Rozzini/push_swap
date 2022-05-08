/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:09:19 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:34:33 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	count_moves(int size, int i, moves_t *moves)
{
	int top;
	int bot;

	top = i - 1;
	bot = size - i + 1;
	if (top < bot)
	{
		moves->steps = top;
		moves->direction  = 0;
	}
	else
	{
		moves->steps = bot;
		moves->direction = 1;
	}
}