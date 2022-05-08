/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_non_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:54:33 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:31:55 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		error_non_num(int argc, char **argv)
{
	int	i;
	int	j;
	int	symb;

	symb = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);	 
}