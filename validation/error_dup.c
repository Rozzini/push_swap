/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:56:12 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:31:51 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		error_dup(node_t **a)
{
	node_t	*current;
	node_t	*iter;

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