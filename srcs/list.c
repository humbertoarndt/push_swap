#include <stdio.h>
#include <stdlib.h>

// =============================================================================
// STRUCT
// =============================================================================

typedef struct t_dlist
{
	struct t_dlist	*prev;
	int				data;
	struct t_dlist	*next;
}				t_dlist;

// =============================================================================
// CREATE
// =============================================================================

t_dlist	*create_node(int data)
{
	t_dlist	*new_node;

	new_node = (t_dlist *) malloc (sizeof(t_dlist));
	if (!new_node)
		return (NULL);
	new_node->prev = new_node;
	new_node->data = data;
	new_node->next = new_node;
	return (new_node);
}

// =============================================================================
// DISPLAY
// =============================================================================

void	display(t_dlist *start)
{
	t_dlist	*temp;
	int		i;

	i = 0;
	temp = start;
	printf("%d:\t|%d|\n", i++, temp->data);
	temp = temp->next;
	while (temp != start)
	{
		printf("%d:\t|%d|\n", i++, temp->data);
		temp = temp->next;
	}
}

// =============================================================================
// INSERT BACK
// =============================================================================

void	insert_back(t_dlist **start, int data)
{
	t_dlist	*last;
	t_dlist	*new_node;

	new_node = create_node(data);
	last = (*start)->prev;
	new_node->prev = last;
	new_node->next = *start;
	(*start)->prev = new_node;
	last->next = new_node;
}

// =============================================================================
// LIST LENGTH
// =============================================================================

int	get_len(t_dlist *start)
{
	int		i;
	t_dlist	*temp;

	i = 0;
	temp = start;
	temp = temp->next;
	while (temp != start)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

// =============================================================================
// INSERT FRONT
// =============================================================================

void	insert_front(t_dlist **start, int data)
{
	t_dlist	*last;
	t_dlist	*new_node;

	new_node = create_node(data);
	last = (*start)->prev;
	new_node->next = *start;
	new_node->prev = last;
	last->next = new_node;
	(*start)->prev = new_node;
	*start = new_node;
}

// =============================================================================
// INSERT AFTER
// =============================================================================

void	insert_after(t_dlist **start, int data1, int data2)
{
	t_dlist	*next;
	t_dlist	*temp;
	t_dlist	*new_node;

	new_node = create_node(data1);
	temp = *start;
	while (temp->data != data2)
		temp = temp->next;
	next = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	new_node->next = next;
	next->prev = new_node;
}

// =============================================================================
// MAIN
// =============================================================================

int	main(void)
{
	t_dlist	*start;
	t_dlist	*mid;
	t_dlist	*end;

	start = create_node(0);
	mid = create_node(50);
	end = create_node(100);

	start->next = mid;
	mid->next = end;
	end->next = start;

	end->prev = mid;
	mid->prev = start;
	start->prev = end;

	insert_back(&start, 150);
	insert_front(&start, -100);
	insert_front(&start, 2);
	insert_after(&start, 42, 50);
	display(start);
	printf("list size:\t|%d|\n", get_len(start));
	return (0);
}
