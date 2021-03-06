/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:57:33 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:17:47 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_node *b, int flag)
{
	int	x;

	x = b->data;
	b->data = b->next->data;
	b->next->data = x;
	if (flag == 1)
		ft_printf("sb\n");
}
