/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:15:41 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:18:10 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calc_block_size(int size)
{
	if (size > 400)
		return (38);
	else if (size > 100)
		return (15);
	else if (size > 50)
		return (8);
	else
		return (4);
}

void	sort_more(t_node **a, t_node **b, int size)
{
	t_node	*a_head;
	int		iter;
	int		block;

	block = calc_block_size(size);
	iter = 1;
	a_head = *a;
	while (list_size(*a) != 0)
	{
		if (a_head->pos >= ((iter - 1) * block) && a_head->pos <= iter * block)
			pb(a, b);
		else
			ra(a, 1);
		if (list_size(*b) == iter * block)
			iter++;
		a_head = *a;
	}
	reset_i(*b);
	push_back(a, b);
}
