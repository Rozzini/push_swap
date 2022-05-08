/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:58:16 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:33:02 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(node_t **a, node_t **b)
{
	node_t *temp;

	temp = *a;
	push(b, temp->data, 0, temp->pos);
	deleteNode(a);
	ft_printf("pb\n");
}