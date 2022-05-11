/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:55:43 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:18:32 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	parse_helper(char **num, int i, t_node **a)
{
	while (i > 0)
	{
		if (ft_strlen(num[i - 1]) > 11)
			return (-1);
		if (dup_push(num[i - 1], a) == -1)
			return (-1);
		free(num[i - 1]);
		i--;
	}
	return (0);
}

int	parse(int argc, char **argv, t_node **a)
{
	char	**numbers;
	int		i;

	while (argc >= 2)
	{
		i = 0;
		if (check_spaces(argv[argc - 1]) == 1)
		{
			numbers = ft_split(argv[argc - 1], ' ');
			while (numbers[i] != NULL)
				i++;
			if (parse_helper(numbers, i, a) != 0)
				return (-1);
			free(numbers);
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
