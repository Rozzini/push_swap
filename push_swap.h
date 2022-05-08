/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:43:36 by mraspors          #+#    #+#             */
/*   Updated: 2022/05/08 05:12:20 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct	node {
	int	data;
	int	i;
	int	pos;
	struct node	*next;
}				node_t;

typedef struct	moves {
	int	steps;
	int	direction;
}				moves_t;

node_t	*find_last(node_t *lst);
node_t	*find_pre_last(node_t *lst);
void	deleteNode(node_t **head);
void	push(node_t **head_ref, int new_data, int i, int pos);

int		error_non_num(int argc, char **argv);
int		check_spaces(char *s);
int		dup_push(char *s, node_t **a);
int		parse(int argc, char **argv, node_t **a);
int		error_dup(node_t **a);
int		check_errors(int argc, char **argv, node_t **a);

void	sa(node_t *a, int flag);
void	sb(node_t *b, int flag);
void	ss(node_t *a, node_t *b);
void	pa(node_t **a, node_t **b);
void	pb(node_t **a, node_t **b);
void	ra(node_t **a, int flag);
void	rb(node_t **b, int flag);
void	rr(node_t **a, node_t **b);
void	rra(node_t **a, int flag);
void	rrb(node_t **b, int flag);
void	rrr(node_t **a, node_t **b);

int		check_sort(node_t *head);
void	reset_i(node_t *head);
int		list_size(node_t *head);
int		errors_for_pos(int index, int *arr, int l);
node_t	*find_min_node(node_t *head, int *arr, int arr_el);
void	find_pos(node_t *head, int l);

int		find_max(node_t *head);
int		find_min(node_t *head);
void	count_moves(int size, int i, moves_t *moves);

void	push_back(node_t **a, node_t **b);
void	check_3_swap(int *a, int *b);
int		check_pos(node_t *head, int j);
void	sort_3(node_t **stack);
void	sort_5(node_t **a, node_t **b);
void	sort_more(node_t **a, node_t **b, int size);
void	sort(node_t **a, node_t **b, int size);

#endif