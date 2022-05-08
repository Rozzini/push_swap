/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:58:55 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:33:08 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb(node_t **b, int flag)
{
	node_t *first;
	node_t *last;

	first = *b;
	last = find_last(*b);
	last->next = first;
	(* b) = first->next;
	first->next = NULL;
	if (flag == 1)
		ft_printf("rb\n");
}