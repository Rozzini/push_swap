/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:59:48 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:33:21 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb(node_t **b, int flag)
{
	node_t *first;
	node_t *last;
	node_t *prelast;

	first = *b;
	prelast = find_pre_last(*b);
	last = find_last(*b);
	prelast->next = NULL;
	last->next = first;
	(* b) = last;
	if (flag == 1)
		ft_printf("rrb\n");
}