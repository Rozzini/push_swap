/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:16:06 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:19:28 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_back(t_node **a, t_node **b)
{
	t_moves	moves;
	int		lst_size;

	lst_size = list_size(*b);
	while (lst_size > 0)
	{
		count_moves(lst_size, find_max(*b), &moves);
		while (moves.steps > 0)
		{
			if (moves.direction == 0)
				rb(b, 1);
			else
				rrb(b, 1);
			moves.steps--;
		}
		pa(a, b);
		reset_i(*b);
		lst_size--;
	}
}
