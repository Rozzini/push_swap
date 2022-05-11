/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_for_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:06:36 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/10 09:44:43 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	errors_for_pos(int index, int *arr, int l)
{
	int	k;

	k = 0;
	while (k < l)
	{
		if (arr[k] == index)
			return (1);
		k++;
	}
	return (0);
}
