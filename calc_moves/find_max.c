/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:08:44 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:34:36 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_max(node_t *head)
{
	node_t *current;
	int		max;
	int		ret;

	current = head;
	max = current->pos;
	ret = current->i;
	while(current != NULL)
	{
		if (current->pos > max)
		{
			ret = current->i;
			max = current->pos;
		}
		current = current->next;
	}
	return (ret);
}