/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:07:00 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:34:12 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

node_t	*find_min_node(node_t *head, int *arr, int arr_el)
{
	node_t	*current;
	node_t	*result;
	int		min;

	current = head;
	min	= 2147483647;
	while (current != NULL)
	{
		if (errors_for_pos(current->i, arr, arr_el) == 0)
		{
			if (current->data < min)
			{
				min = current->data;
				result = current;
			}
		}
		current = current->next;
	}
	return (result);
}