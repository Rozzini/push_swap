/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_non_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:54:33 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:03:26 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_for_digits(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			count++;
		i++;
	}
	if (count > 0)
		return (0);
	else
		return (1);
}

int	error_helper(char *s)
{
	int	j;

	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] >= '0' && s[j] <= '9')
		{
			if (s[j + 1] != ' ' && s[j + 1] != '\0'
				&& !(s[j + 1] >= '0' && s[j + 1] <= '9'))
				return (1);
			j++;
		}
		else if (s[j] == '-' || s[j] == '+')
		{
			if (s[j + 1] == '-' || s[j + 1] == '+')
				return (1);
			j++;
		}
		else if (s[j] == ' ')
			j++;
	}
	return (0);
}

int	error_non_num(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_for_digits(argv[i]) == 1)
			return (1);
		if (error_helper(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
