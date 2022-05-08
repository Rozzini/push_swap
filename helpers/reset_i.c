/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:05:39 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:34:28 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reset_i(node_t *head)
{
	node_t	*current = head;
	int		i;

	i = 1;
	while (current != NULL)
	{
		current->i = i;
		i++;
		current = current->next;
	}
}