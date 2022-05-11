/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:43:36 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/11 13:21:53 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct node {
	int			data;
	int			i;
	int			pos;
	struct node	*next;
}				t_node;

typedef struct moves {
	int	steps;
	int	direction;
}				t_moves;

t_node	*find_last(t_node *lst);
t_node	*find_pre_last(t_node *lst);
void	delete_node(t_node **head);
void	push(t_node **head_ref, int new_data, int i, int pos);

int		error_non_num(int argc, char **argv);
int		check_spaces(char *s);
int		dup_push(char *s, t_node **a);
int		parse(int argc, char **argv, t_node **a);
int		error_dup(t_node **a);
int		check_errors(int argc, char **argv, t_node **a);

void	sa(t_node *a, int flag);
void	sb(t_node *b, int flag);
void	ss(t_node *a, t_node *b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a, int flag);
void	rb(t_node **b, int flag);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a, int flag);
void	rrb(t_node **b, int flag);
void	rrr(t_node **a, t_node **b);

int		check_sort(t_node *head);
void	reset_i(t_node *head);
int		list_size(t_node *head);
int		errors_for_pos(int index, int *arr, int l);
t_node	*find_min_node(t_node *head, int *arr, int arr_el);
void	find_pos(t_node *head, int l);

int		find_max(t_node *head);
int		find_min(t_node *head);
void	count_moves(int size, int i, t_moves *moves);

void	push_back(t_node **a, t_node **b);
void	check_3_swap(int *a, int *b);
int		cp(t_node *head, int j);
void	sort_3(t_node **stack);
void	sort_5(t_node **a, t_node **b);
void	sort_more(t_node **a, t_node **b, int size);
void	sort(t_node **a, t_node **b, int size);

#endif