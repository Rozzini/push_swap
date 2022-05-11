/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:53:22 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:17:16 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_node **head_ref, int new_data, int i, int pos)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	new_node->data = new_data;
	new_node->i = i;
	new_node->pos = pos;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
