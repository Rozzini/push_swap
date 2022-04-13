#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
} node_t;

void deleteNode(node_t **head_ref)
{
    node_t *temp = *head_ref;
	node_t *prev;
 
    if(temp != NULL) 
	{
        *head_ref = temp->next;
        free(temp); 
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void push(node_t **head_ref, int new_data)
{
	
    node_t *new_node;

	new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data  = new_data;
	new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d ::: %p\n", current->data, current->next);
        current = current->next;
    }
}

void sa(node_t *a)
{
	int		x;

	x = a->data;
	a->data = a->next->data;
	a->next->data = x;
}

void sb(node_t *b)
{
	int		x;

	x = b->data;
	b->data = b->next->data;
	b->next->data = x;
}

void ss(node_t *a, node_t *b)
{
	sa(a);
	sb(b);
}

// void pa()
// {

// }

void pb(node_t *a, node_t *b)
{
	node_t *temp;

	temp = a;
	a = a->next;
	if (b == NULL)
	{
		b = temp;
		b->next = NULL;
	}
	else
	{
		temp->next = b;
		b = temp;
	}
	deleteNode(&temp);
}

// void ra()
// {

// }

// void rb()
// {

// }

// void rr()
// {

// }

// void rra()
// {

// }

// void rrb()
// {

// }

// void rrr()
// {

// }

int main(int argc, char **argv)
{
    node_t	*a;
	node_t	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = argc - 1;
	while (i > 0)
	{
		push(&a, atoi(argv[i]));
		i--;
	}
	printf("list a:\n");
	print_list(a);
	printf("---------------------------------\n");
	printf("list b:\n");
	print_list(b);
	printf("0000000000000000000000000000000000\n");
	pb(a, b);
	printf("list a:\n");
	print_list(a);
	printf("---------------------------------\n");
	printf("list b:\n");
	print_list(b);
	return 0;
}