/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:07:28 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:34:20 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_pos(node_t *head, int l)
{
	node_t	*current;
	int		arr[l];
	int		i;

	i = 0;
	while (i < l)
	{
		current = find_min_node(head, arr, i );
		current->pos = i + 1;
		arr[i] = current->i;
		i++;
	}
}