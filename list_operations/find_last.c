/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:52:59 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:17:12 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_last(t_node *lst)
{
	t_node	*node;

	if (lst == NULL)
		return (0);
	node = lst;
	while (node->next != NULL)
		node = node->next;
	return (node);
}
