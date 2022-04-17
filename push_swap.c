#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct node {
    int data;
	int i;
    struct node * next;
} node_t;

typedef struct data {
	int	i_max;
	int i_min;

	int max_m_t;
	int max_m_b;
	
	int min_m_t;
	int min_m_b;

	// 0 - r || 1 - rr
	int	direction;
	int moves;
	int	size;
} data_t;

int		error_non_num(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);	 
}

int		error_dup(int argc, char **argv)
{
	long long	current;
	int	temp;
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		current = ft_atoi(argv[i]);
		if (current > 2147483647 || current < -2147483648)
			return (1);
		j = 1 + i;
		while (j < argc)
		{
			temp = ft_atoi(argv[j]);
			if (current == temp)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_errors(int argc, char **argv)
{
	if (argc <= 1)
		return (1);
	if (error_non_num(argc, argv) == 1)
		return (1);
	if (error_dup(argc, argv) == 1)
		return (1);
	return (0);
}

node_t	*find_last(node_t *lst)
{
	node_t	*node;

	if (lst == NULL)
		return (0);
	node = lst;
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

node_t	*find_pre_last(node_t *lst)
{
	node_t	*node;
	node_t	*temp;

	if (lst == NULL)
		return (0);
	node = lst;
	while (node->next != NULL)
	{
		temp = node;
		node = node->next;
	}
	return (temp);
}

void	deleteNode(node_t **head_ref)
{
    node_t *temp = *head_ref;
	node_t *prev;
 
	prev = NULL;
    if(temp != NULL) 
	{
        *head_ref = temp->next;
        free(temp); 
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void	push(node_t **head_ref, int i, int new_data)
{
	
    node_t *new_node;

	new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data  = new_data;
	new_node->i		= i;
	new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void	print_list(node_t *a, node_t *b) 
{
    node_t *current_a = a;
	node_t *current_b = b;

	printf("-------\n");
    while (current_a != NULL || current_b != NULL) {
		if (current_a == NULL)
        	printf("- ::: %d\n",current_b->data);
		else if (current_b == NULL)
			printf("%d ::: -\n", current_a->data);
		else
			printf("%d ::: %d\n", current_a->data, current_b->data);
		if (current_a != NULL)
        	current_a = current_a->next;
		if (current_b != NULL)
		current_b = current_b->next;
    }
	printf("A --- B\n");
}

void	sa(node_t *a)
{
	int		x;

	x = a->data;
	a->data = a->next->data;
	a->next->data = x;
}

void	sb(node_t *b)
{
	int		x;

	x = b->data;
	b->data = b->next->data;
	b->next->data = x;
}

void	ss(node_t *a, node_t *b)
{
	sa(a);
	sb(b);
}

void	pa(node_t **a, node_t **b)
{
	node_t *temp;

	temp = *b;
	push(a, 0, temp->data);
	deleteNode(b);
}

void	pb(node_t **a, node_t **b)
{
	node_t *temp;

	temp = *a;
	push(b, 0, temp->data);
	deleteNode(a);
}

void	ra(node_t **a)
{
	node_t *first;
	node_t *last;

	first = *a;
	last = find_last(*a);
	last->next = first;
	(* a) = first->next;
	first->next = NULL;
}

void	rb(node_t **b)
{
	node_t *first;
	node_t *last;

	first = *b;
	last = find_last(*b);
	last->next = first;
	(* b) = first->next;
	first->next = NULL;
}

void	rr(node_t **a, node_t **b)
{
	ra(a);
	rb(b);
}

void	rra(node_t **a)
{
	node_t *first;
	node_t *last;
	node_t *prelast;

	first = *a;
	prelast = find_pre_last(*a);
	last = find_last(*a);
	prelast->next = NULL;
	last->next = first;
	(* a) = last;
}

void	rrb(node_t **b)
{
	node_t *first;
	node_t *last;
	node_t *prelast;

	first = *b;
	prelast = find_pre_last(*b);
	last = find_last(*b);
	prelast->next = NULL;
	last->next = first;
	(* b) = last;
}

void	rrr(node_t **a, node_t **b)
{
	rra(a);
	rrb(b);
}

int		check_sort(node_t *head)
{
	node_t * current = head;

    while (current->next != NULL) 
	{
        if (current->data > current->next->data)
			return (1);
        current = current->next;
    }
	return (0);
}

int		find_max(node_t *head)
{
	node_t	*current = head;
	int		max;
	int		i;

	i = current->i;
	max	= current->data;
	while (current != NULL)
	{
		if (current->data > max)
		{
			max = current->data;
			i = current->i;
		}
		current = current->next;
	}
	return (i);
}

int		find_min(node_t *head)
{
	node_t	*current = head;
	int		min;
	int		i;

	i = current->i;
	min	= current->data;
	while (current != NULL)
	{
		if (current->data < min)
		{
			min = current->data;
			i = current->i;
		}
		current = current->next;
	}
	return (i);
}

int		find_last_i(node_t *head)
{
	node_t	*current = head;
	int		i;

	i = 0;
	while (current != NULL)
	{
		i = current->i;
		current = current->next;
	}
	return (i);
}

void	reset_i(node_t *head)
{
	node_t	*current = head;
	int		i;

	i = 1;
	while (current != NULL)
	{
		current->i = i;
		i++;
		current = current->next;
	}
}

void	calc_pos(data_t *data, node_t *a)
{
	data->size = find_last_i(a);
	data->i_max = find_max(a);
	data->i_min = find_min(a);
	data->max_m_t = data->i_max - 1;
	data->min_m_t = data->i_min - 1;
	data->max_m_b = data->size - data->i_max + 1;
	data->min_m_b = data->size - data->i_min + 1;
	data->moves = data->max_m_t;
	data->direction = 0;
	if(data->moves > data->min_m_t)
		data->moves = data->min_m_t;
	if (data->moves > data->min_m_b)
	{
		data->moves = data->min_m_b;
		data->direction = 1;
	}
	if (data->moves > data->max_m_b)
	{
		data->moves = data->max_m_b;
		data->direction = 1;
	}
}

void	sort(node_t **a, node_t **b)
{
		data_t	data;
	int		i;
	int		j = 0;
	while (/*head_a->next != NULL*/j < 5)
	{
		i = 0;
		calc_pos(&data, *a);
		while (i < data.moves)
		{
			if (data.direction == 0)
				ra(a);
			else
				rra(a);
			i++;
		}
		pb(a, b);
		printf("moves: %d\n", i);
		print_list(*a, *b);
	}
}

int		main(int argc, char **argv)
{
    node_t	*a;
	node_t	*b;
	int		i;

	if (check_errors(argc, argv) == 1)
	{
		printf("Error\n");
		return (0);
	}
	a = NULL;
	b = NULL;
	i = argc - 1;
	while (i > 0)
	{
		push(&a, i, ft_atoi(argv[i]));
		i--;
	}
	print_list(a, b);
	sort(&a, &b);
	if (check_sort(a) == 0)
		printf("sorted\n");
	else
		printf("not sorted\n");
	return (0);
}