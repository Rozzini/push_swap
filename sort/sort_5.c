/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:15:09 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:32:43 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_5(node_t **a, node_t **b)
{
	int		i;
	int		min;
	moves_t	moves;

	i = 0;
	while (i < 2)
	{
		min = find_min(*a);
		count_moves(5 - i, min, &moves);
		while (moves.steps > 0)
		{
			if (moves.direction == 0)
				ra(a, 1);
			else
				rra(a, 1);
			moves.steps--;
		}
		pb(a, b);
		reset_i(*a);
		i++;
	}
	if (check_sort(*b) == 0)
		sb(*b, 1);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}