/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:59:34 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:33:18 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(node_t **a, int flag)
{
	node_t *first;
	node_t *last;
	node_t *prelast;

	first = *a;
	prelast = find_pre_last(*a);
	last = find_last(*a);
	prelast->next = NULL;
	last->next = first;
	(* a) = last;
	if (flag == 1)
		ft_printf("rra\n");
}