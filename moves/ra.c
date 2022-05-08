/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:58:29 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:33:05 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(node_t **a, int flag)
{
	node_t *first;
	node_t *last;

	first = *a;
	last = find_last(*a);
	last->next = first;
	(* a) = first->next;
	first->next = NULL;
	if (flag == 1)
		ft_printf("ra\n");
}