/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:15:41 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:32:46 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_more(node_t **a, node_t **b, int size)
{
	node_t	*a_head;
	int		iter;
	int		block;

	if (size > 400)
		block = 40;
	else if (size > 100)
		block = 12;
	else if (size > 50)
		block = 8;
	else
		block = 4;
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