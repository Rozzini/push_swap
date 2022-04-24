#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct node {
    int data;
	int i;
	int	pos;
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

void	push(node_t **head_ref, int i, int new_data, int pos)
{
	
    node_t *new_node;

	new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data  = new_data;
	new_node->i		= i;
	new_node->pos	= pos;
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
        	printf("- pos: - ::: %d pos: %d\n",current_b->data, current_b->pos);
		else if (current_b == NULL)
			printf("%d pos: %d ::: - pos: - \n", current_a->data, current_a->pos);
		else
			printf("%d pos: %d ::: %d pos: %d \n", current_a->data, current_a->pos, current_b->data, current_b->pos);
		if (current_a != NULL)
        	current_a = current_a->next;
		if (current_b != NULL)
		current_b = current_b->next;
    }
	printf("   A    ---   B   \n");
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
	push(a, 0, temp->data, temp->pos);
	deleteNode(b);
}

void	pb(node_t **a, node_t **b)
{
	node_t *temp;

	temp = *a;
	push(b, 0, temp->data, temp->pos);
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

void	node_put_pos(node_t *head, int data, int pos)
{
	node_t	*current;

	current = head;
	while (current != NULL)
	{
		if (current->data == data)
		{
			current->pos = pos;
		}
		current = current->next;
	}
}

int		errors_for_pos(int index, int *arr, int l)
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

node_t		*find_min_node(node_t *head, int *arr, int arr_el)
{
	node_t	*current;
	node_t	*result;
	int		min;

	current = head;
	min	= 2147483647;
	while (current != NULL)
	{
		if (errors_for_pos(current->i, arr, arr_el) == 0)
		{
			if (current->data < min)
			{
				min = current->data;
				result = current;
			}
		}
		current = current->next;
	}
	return (result);
}

void	find_pos(node_t *head, int l)
{
	node_t	*current;
	int		arr[l];
	int		i;

	i = 0;
	while (i < l)
	{
		current = find_min_node(head, arr, i );
		current->pos = i + 1;
		printf("cuurent info: data - %d, i - %d\n", current->data, current->i);
		arr[i] = current->i;
		i++;
	}
	for (int k = 0; k < l; k++)
		printf("%d ,", arr[k]);
	printf("\n");
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
		push(&a, i, ft_atoi(argv[i]), 0);
		i--;
	}
	print_list(a, b);
	find_pos(a, argc - 1);
	print_list(a, b);
	return (0);
}