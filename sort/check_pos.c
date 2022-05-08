/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:14:30 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:32:33 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_pos(node_t *head, int j)
{
	int	x[3];

	x[0] = head->pos;
	x[1] = head->next->pos;
	x[2] = head->next->next->pos;
	if (x[0] > x[2])
		check_3_swap(&x[0], &x[2]);
	if (x[0] > x[1])
		check_3_swap(&x[0], &x[1]);
	if (x[1] > x[2])
		check_3_swap(&x[1], &x[2]);
	return (x[j - 1]);
}