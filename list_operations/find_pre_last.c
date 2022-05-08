/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pre_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:53:08 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:33:49 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

node_t	*find_pre_last(node_t *lst)
{
	node_t	*node;
	node_t	*temp;

	if (lst == NULL)
		return (0);
	node = lst;
	while (node->next != NULL)
	{
		temp = node;
		node = node->next;
	}
	return (temp);
}