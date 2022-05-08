/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:55:43 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:32:01 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	parse(int argc, char **argv, node_t **a)
{
	char		**numbers;
	int			i;

	while (argc >= 2)
	{
		i = 0;
		if (check_spaces(argv[argc - 1]) == 1)
		{
			numbers = ft_split(argv[argc - 1], ' ');
			while (numbers[i] != NULL)
				i++;
			while (i > 0)
			{
				if (dup_push(numbers[i - 1], a) == -1)
					return (-1);
				i--;
			}
		}
		else
		{
			if (dup_push(argv[argc - 1], a) == -1)
					return (-1);
		}
		argc--;
	}
	return (1);
}