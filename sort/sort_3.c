/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:14:46 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:36:31 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(node_t **stack)
{
	node_t	*head;

	head = *stack;
	if (head->pos == check_pos(head, 1) && head->next->pos == check_pos(head, 3) && head->next->next->pos == check_pos(head, 2))
	{
		rra(stack, 1);
		sa(*stack, 1);
	}
	else if (head->pos == check_pos(head, 2) && head->next->pos == check_pos(head, 1) && head->next->next->pos == check_pos(head, 3))
		sa(*stack, 1);
	else if (head->pos == check_pos(head, 2) && head->next->pos == check_pos(head, 3) && head->next->next->pos == check_pos(head, 1))
		rra(stack, 1);
	else if (head->pos == check_pos(head, 3) && head->next->pos == check_pos(head, 1) && head->next->next->pos == check_pos(head, 2))
		ra(stack, 1);
	else if (head->pos == check_pos(head, 3) && head->next->pos == check_pos(head, 2) && head->next->next->pos == check_pos(head, 1))
	{
		sa(*stack, 1);
		rra(stack, 1);
	}
}