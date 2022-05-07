#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
#pragma region Structs

typedef struct node {
    int data;
	int i;
	int	pos;
    struct node * next;
} node_t;

typedef struct moves {
    int steps;
	int direction;
} moves_t;
#pragma endregion Structs

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#pragma region Basic_operatons_with_lists

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

void	deleteNode(node_t **head)
{
	node_t	*temp;
     
    temp = *head;    
    *head = (*head)->next;
    free(temp);
}

void	push(node_t **head_ref, int new_data, int i, int pos)
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
        	printf("- pos: - i: - ::: %d pos: %d i: %d\n",current_b->data, current_b->pos, current_b->i);
		else if (current_b == NULL)
			printf("%d pos: %d i: %d ::: - pos: - i: - \n", current_a->data, current_a->pos, current_a->i);
		else
			printf("%d pos: %d i: %d ::: %d pos: %d i: %d \n", current_a->data, current_a->pos, current_a->i, current_b->data, current_b->pos, current_b->i);
		if (current_a != NULL)
        	current_a = current_a->next;
		if (current_b != NULL)
		current_b = current_b->next;
    }
	printf("   A        ---       B   \n");
}
#pragma endregion Basic_operatons_with_lists

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#pragma region main_params_validation

int		error_non_num(int argc, char **argv)
{
	int	i;
	int	j;
	int	symb;

	symb = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);	 
}

int		check_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	dup_push(char *s, node_t **a)
{
	long long	num;

	num = ft_atoi(s);
	if (num > 2147483647 || num < -2147483648)
		return (-1);
	push(a, num, 0, 0);
	return (0);
}

int	parse(int argc, char **argv, node_t **a)
{
	char		**numbers;
	int			i;

	while (argc >= 2)
	{
		i = 0;
		if (check_spaces(argv[argc - 1]) == 1)
		{
			numbers = ft_split(argv[argc - 1], ' ');
			while (numbers[i] != NULL)
				i++;
			while (i > 0)
			{
				if (dup_push(numbers[i - 1], a) == -1)
					return (-1);
				i--;
			}
		}
		else
		{
			if (dup_push(argv[argc - 1], a) == -1)
					return (-1);
		}
		argc--;
	}
	return (1);
}

int		error_dup(node_t **a)
{
	node_t	*current;
	node_t	*iter;

	current = *a;
	while (current != NULL)
	{
		iter = current->next;
		while (iter != NULL)
		{
			if (current->data == iter->data)
				return (1);
			iter = iter->next;
		}
		current = current->next;
	}
	return (0);
}

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
#pragma endregion main_params_validation

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#pragma region Moves
void	sa(node_t *a, int flag)
{
	int		x;

	x = a->data;
	a->data = a->next->data;
	a->next->data = x;
	if (flag == 1)
		ft_printf("sa\n");
}

void	sb(node_t *b, int flag)
{
	int		x;

	x = b->data;
	b->data = b->next->data;
	b->next->data = x;
	if (flag == 1)
		ft_printf("sb\n");
}

void	ss(node_t *a, node_t *b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	pa(node_t **a, node_t **b)
{
	node_t *temp;

	temp = *b;
	push(a, temp->data, 0, temp->pos);
	deleteNode(b);
	ft_printf("pa\n");
}

void	pb(node_t **a, node_t **b)
{
	node_t *temp;

	temp = *a;
	push(b, temp->data, 0, temp->pos);
	deleteNode(a);
	ft_printf("pb\n");
}

void	ra(node_t **a, int flag)
{
	node_t *first;
	node_t *last;

	first = *a;
	last = find_last(*a);
	last->next = first;
	(* a) = first->next;
	first->next = NULL;
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(node_t **b, int flag)
{
	node_t *first;
	node_t *last;

	first = *b;
	last = find_last(*b);
	last->next = first;
	(* b) = first->next;
	first->next = NULL;
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(node_t **a, node_t **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}

void	rra(node_t **a, int flag)
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
	if (flag == 1)
		ft_printf("rra\n");
}

void	rrb(node_t **b, int flag)
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
	if (flag == 1)
		ft_printf("rrb\n");
}

void	rrr(node_t **a, node_t **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}
#pragma endregion Moves

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#pragma region helpers
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

int		list_size(node_t *head)
{
	node_t	*current;
	int		i;

	current = head;
	i = 0;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
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

node_t	*find_min_node(node_t *head, int *arr, int arr_el)
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
		arr[i] = current->i;
		i++;
	}
}

#pragma endregion helpers

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#pragma region positions_moves

int		find_max(node_t *head)
{
	node_t *current;
	int		max;
	int		ret;

	current = head;
	max = current->pos;
	ret = current->i;
	while(current != NULL)
	{
		if (current->pos > max)
		{
			ret = current->i;
			max = current->pos;
		}
		current = current->next;
	}
	return (ret);
}

int		find_min(node_t *head)
{
	node_t *current;
	int		min;
	int		ret;

	current = head;
	min = current->pos;
	ret = current->i;
	while(current != NULL)
	{
		if (current->pos < min)
		{
			ret = current->i;
			min = current->pos;
		}
		current = current->next;
	}
	return (ret);
}

void	count_moves(int size, int i, moves_t *moves)
{
	int top;
	int bot;

	top = i - 1;
	bot = size - i + 1;
	if (top < bot)
	{
		moves->steps = top;
		moves->direction  = 0;
	}
	else
	{
		moves->steps = bot;
		moves->direction = 1;
	}
}
#pragma endregion position_moves

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#pragma region sort3

void	case31(node_t **head)
{
	rra(head, 1);
	sa(*head, 1);
}

void	case32(node_t **head)
{
	sa(*head, 1);
}

void	case33(node_t **head)
{
	rra(head, 1);
}

void	case34(node_t **head)
{
	ra(head, 1);
}

void	case35(node_t **head)
{
	sa(*head, 1);
	rra(head, 1);
}

void	check_3_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		check_pos(node_t *head, int j)
{
	int	x[3];

	x[0] = head->pos;
	x[1] = head->next->pos;
	x[2] = head->next->next->pos;
	if (x[0] > x[2])
		check_3_swap(&x[0], &x[2]);
	if (x[0] > x[1])
		check_3_swap(&x[0], &x[1]);
	if (x[1] > x[2])
		check_3_swap(&x[1], &x[2]);
	return (x[j - 1]);
}

void	sort_3(node_t **stack)
{
	node_t	*head;

	head = *stack;
	if (head->pos == check_pos(head, 1) && head->next->pos == check_pos(head, 3) && head->next->next->pos == check_pos(head, 2))
		case31(stack);
	else if (head->pos == check_pos(head, 2) && head->next->pos == check_pos(head, 1) && head->next->next->pos == check_pos(head, 3))
		case32(stack);
	else if (head->pos == check_pos(head, 2) && head->next->pos == check_pos(head, 3) && head->next->next->pos == check_pos(head, 1))
		case33(stack);
	else if (head->pos == check_pos(head, 3) && head->next->pos == check_pos(head, 1) && head->next->next->pos == check_pos(head, 2))
		case34(stack);
	else if (head->pos == check_pos(head, 3) && head->next->pos == check_pos(head, 2) && head->next->next->pos == check_pos(head, 1))
		case35(stack);
}

#pragma endregion sort3

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#pragma region sort5

void	sort_5(node_t **a, node_t **b)
{
	int		i;
	int		min;
	moves_t	moves;

	i = 0;
	while (i < 2)
	{
		min = find_min(*a);
		count_moves(5 - i, min, &moves);
		while (moves.steps > 0)
		{
			if (moves.direction == 0)
				ra(a, 1);
			else
				rra(a, 1);
			moves.steps--;
		}
		pb(a, b);
		reset_i(*a);
		i++;
	}
	if (check_sort(*b) == 0)
		sb(*b, 1);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}

#pragma endregion sort5

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#pragma region sort

void	push_back(node_t **a, node_t **b)
{
	moves_t	moves;
	int		lst_size;

	lst_size = list_size(*b);
	while (lst_size > 0)
	{
		count_moves(lst_size, find_max(*b), &moves);
		while (moves.steps > 0)
		{
			if (moves.direction == 0)
				rb(b, 1);
			else
				rrb(b, 1);
			moves.steps--;
		}
		pa(a, b);
		reset_i(*b);
		lst_size--;
	}
}

void	sort_more(node_t **a, node_t **b, int size)
{
	node_t	*a_head;
	int		iter;
	int		block;

	if (size > 400)
		block = 40;
	else if (size > 100)
		block = 12;
	else if (size > 50)
		block = 8;
	else
		block = 4;
	iter = 1;
	a_head = *a;
	while (list_size(*a) != 0)
	{
		if (a_head->pos >= ((iter - 1) * block) && a_head->pos <= iter * block)
			pb(a, b);
		else
			ra(a, 1);
		if (list_size(*b) == iter * block)
			iter++;
		a_head = *a;
	}
	reset_i(*b);
	push_back(a, b);
}
#pragma endregion sort

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
#pragma region sorting

void	sort(node_t **a, node_t **b, int size)
{
	if (size == 3)
		sort_3(a);
	else if (size == 5)
		sort_5(a, b);
	else
		sort_more(a, b, size);
}

#pragma endregion sorting

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

int		main(int argc, char **argv)
{
    node_t	*a;
	node_t	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (check_errors(argc, argv, &a) == -1)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (check_sort(a) == 0)
	{
		ft_printf("sorted\n");
		return (0);
	}
	size = list_size(a);
	reset_i(a);
	find_pos(a, size);
	print_list(a, b);
	sort(&a, &b, size);
	print_list(a, b);
	return (0);
}