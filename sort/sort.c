/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:16:37 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:18:14 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_node **a, t_node **b, int size)
{
	if (size == 2 && check_sort(*a) == 1)
		sa(*a, 1);
	else if (size == 3)
		sort_3(a);
	else if (size == 5)
		sort_5(a, b);
	else
		sort_more(a, b, size);
}
