/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:14:46 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:18:05 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_node **stack)
{
	t_node	*head;
	int		*x;

	head = *stack;
	x = (int [3]){head->pos, head->next->pos, head->next->next->pos};
	if (x[0] == cp(head, 1) && x[1] == cp(head, 3) && x[2] == cp(head, 2))
	{
		rra(stack, 1);
		sa(*stack, 1);
	}
	else if (x[0] == cp(head, 2) && x[1] == cp(head, 1) && x[2] == cp(head, 3))
		sa(*stack, 1);
	else if (x[0] == cp(head, 2) && x[1] == cp(head, 3) && x[2] == cp(head, 1))
		rra(stack, 1);
	else if (x[0] == cp(head, 3) && x[1] == cp(head, 1) && x[2] == cp(head, 2))
		ra(stack, 1);
	else if (x[0] == cp(head, 3) && x[1] == cp(head, 2) && x[2] == cp(head, 1))
	{
		sa(*stack, 1);
		rra(stack, 1);
	}
}
