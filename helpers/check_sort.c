/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:05:17 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:16:27 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sort(t_node *head)
{
	t_node	*current;

	current = head;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (1);
		current = current->next;
	}
	return (0);
}
