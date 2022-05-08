/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:08:58 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:14:02 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_min(node_t *head)
{
	node_t *current;
	int		min;
	int		ret;

	current = head;
	min = current->pos;
	ret = current->i;
	while(current != NULL)
	{
		if (current->pos < min)
		{
			ret = current->i;
			min = current->pos;
		}
		current = current->next;
	}
	return (ret);
}