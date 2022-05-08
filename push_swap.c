/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 05:16:37 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:39:23 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
    node_t	*a;
	node_t	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (check_errors(argc, argv, &a) == -1)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (check_sort(a) == 0)
	{
		ft_printf("sorted\n");
		return (0);
	}
	size = list_size(a);
	reset_i(a);
	find_pos(a, size);
	sort(&a, &b, size);
	return (0);
}