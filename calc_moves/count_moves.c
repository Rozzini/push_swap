/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:09:19 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:19:08 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	count_moves(int size, int i, t_moves *moves)
{
	int	top;
	int	bot;

	top = i - 1;
	bot = size - i + 1;
	if (top < bot)
	{
		moves->steps = top;
		moves->direction = 0;
	}
	else
	{
		moves->steps = bot;
		moves->direction = 1;
	}
}
