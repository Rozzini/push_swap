/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:07:28 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:16:41 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_pos(t_node *head, int l)
{
	t_node	*current;
	int		arr[50000];
	int		i;

	i = 0;
	while (i < l)
	{
		current = find_min_node(head, arr, i);
		current->pos = i + 1;
		arr[i] = current->i;
		i++;
	}
}
