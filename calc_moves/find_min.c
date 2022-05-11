/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:08:58 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:16:56 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_node *head)
{
	t_node	*current;
	int		min;
	int		ret;

	current = head;
	min = current->pos;
	ret = current->i;
	while (current != NULL)
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
