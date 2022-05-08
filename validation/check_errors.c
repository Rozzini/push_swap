/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:56:34 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:31:20 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_errors(int argc, char **argv, node_t **a)
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