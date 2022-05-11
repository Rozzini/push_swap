/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:07:00 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:16:38 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_min_node(t_node *head, int *arr, int arr_el)
{
	t_node	*current;
	t_node	*result;
	int		min;

	current = head;
	min = 2147483647;
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
