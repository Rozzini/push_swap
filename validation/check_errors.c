/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:56:34 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:18:18 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_errors(int argc, char **argv, t_node **a)
{
	if (argc <= 1)
		return (-1);
	if (error_non_num(argc, argv) == 1)
		return (-1);
	if (parse(argc, argv, a) == -1)
		return (-1);
	if (error_dup(a) == 1)
		return (-1);
	return (0);
}
