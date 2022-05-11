/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:15:09 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:19:24 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3_and_push(t_node **a, t_node **b)
{
	sort_3(a);
	pa(a, b);
	pa(a, b);
}

void	sort_5(t_node **a, t_node **b)
{
	int		i;
	int		min;
	t_moves	moves;

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
	sort_3_and_push(a, b);
}
