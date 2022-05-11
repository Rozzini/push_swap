/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:56:12 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:18:25 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_dup(t_node **a)
{
	t_node	*current;
	t_node	*iter;

	current = *a;
	while (current != NULL)
	{
		iter = current->next;
		while (iter != NULL)
		{
			if (current->data == iter->data)
				return (1);
			iter = iter->next;
		}
		current = current->next;
	}
	return (0);
}
