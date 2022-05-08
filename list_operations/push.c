/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:53:22 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:33:54 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(node_t **head_ref, int new_data, int i, int pos)
{
	
    node_t *new_node;

	new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data  = new_data;
	new_node->i		= i;
	new_node->pos	= pos;
	new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}