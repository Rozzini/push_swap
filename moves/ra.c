/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:58:29 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:17:28 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **a, int flag)
{
	t_node	*first;
	t_node	*last;

	first = *a;
	last = find_last(*a);
	last->next = first;
	(*a) = first->next;
	first->next = NULL;
	if (flag == 1)
		ft_printf("ra\n");
}
