/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:05:39 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:16:46 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reset_i(t_node *head)
{
	t_node	*current;
	int		i;

	current = head;
	i = 1;
	while (current != NULL)
	{
		current->i = i;
		i++;
		current = current->next;
	}
}
