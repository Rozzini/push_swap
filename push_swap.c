/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 05:16:37 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:18:38 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_node **a)
{
	t_node	*temp;

	temp = *a;
	while (temp != NULL)
	{
		delete_node(a);
		temp = *a;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (check_errors(argc, argv, &a) == -1)
	{
		ft_printf("Error\n");
		free_all(&a);
		return (0);
	}
	if (check_sort(a) == 0)
	{
		free_all(&a);
		return (0);
	}
	size = list_size(a);
	reset_i(a);
	find_pos(a, size);
	sort(&a, &b, size);
	free_all(&a);
	return (0);
}
