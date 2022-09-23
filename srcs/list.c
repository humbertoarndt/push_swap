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

	if (start != NULL)
	{
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
	else
		printf("List empty\n");
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
// LIST LENGTH
// =============================================================================

int	get_len(t_dlist *start)
{
	int		i;
	t_dlist	*temp;

	i = 0;
	temp = start;
	if (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	while (temp != start)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

// =============================================================================
// INSERT POSITION
// =============================================================================

void	insert_at(t_dlist **start, int data, int position)
{
	int		i;
	t_dlist	*temp;
	t_dlist	*new_node;

	i = 0;
	new_node = create_node(data);
	temp = *start;
	if (position < 1 || position > get_len(*start))
		return ;
	else
	{
		temp = *start;
		while (i++ < (position -1))
			temp = temp->next;
		new_node->next = temp->next;
		new_node->next->prev = new_node;
		new_node->prev = temp;
		temp->next = new_node;
	}
}

// =============================================================================
// DELETE FIRST
// =============================================================================

void	del_first(t_dlist **start)
{
	t_dlist	*temp;
	t_dlist	*first_node;

	if (*start != NULL)
	{
		if ((*start)->next == *start)
			*start = NULL;
		else
		{
			temp = *start;
			first_node = *start;
			while (temp->next != *start)
				temp = temp->next;
			*start = (*start)->next;
			(*start)->prev = temp;
			temp->next = *start;
			free(first_node);
		}
	}
}

// =============================================================================
// DELETE LAST
// =============================================================================

void	del_last(t_dlist **start)
{
	t_dlist	*temp;
	t_dlist	*last_node;

	if (*start != NULL)
	{
		if ((*start)->next == *start)
			*start = NULL;
		else
		{
			temp = *start;
			while (temp->next->next != *start)
				temp = temp->next;
			last_node = temp->next;
			temp->next = *start;
			(*start)->prev = temp;
			free(last_node);
		}
	}
}

// =============================================================================
// DELETE POSITION
// =============================================================================

void	del_at(t_dlist **start, int position)
{
	int		i;
	int		elements;
	t_dlist	*temp;
	t_dlist	*del_node;

	i = 0;
	elements = 0;
	temp = *start;
	del_node = *start;
	if (temp != NULL)
	{
		elements++;
		temp = temp->next;
	}
	while (temp != *start)
	{
		elements++;
		temp = temp->next;
	}
	if (position < 1 || position > elements)
		return ;
	else
	{
		temp = *start;
		while (++i < position - 1)
			temp = temp->next;
		del_node = temp->next;
		temp->next = temp->next->next;
		temp->next->prev = temp;
		free(del_node);
	}
}

// =============================================================================
// DELETE ALL
// =============================================================================

void	del_all(t_dlist **start)
{
	t_dlist	*temp;
	t_dlist	*current;

	if (*start != NULL)
	{
		current = (*start)->next;
		while (current != *start)
		{
			temp = current->next;
			free (current);
			current = temp;
		}
		free(*start);
		*start = NULL;
	}
}

// =============================================================================
// SEARCH ELEMENT
// =============================================================================

void	search_element(t_dlist *start, int value)
{
	int		i;
	int		found;
	t_dlist	*temp;

	i = 0;
	found = 0;
	temp = start;
	if (temp != NULL)
	{
		while (1)
		{
			i++;
			if (temp->data == value)
			{
				found++;
				break ;
			}
			temp = temp->next;
			if (temp == start)
				break ;
		}
		if (found == 1)
			printf("%d is found at index = %d.\n", value, i);
		else
			printf("%d is not found in the list.\n", value);
	}
	else
		printf("Empty list.\n");
}

// =============================================================================
// REVERSE LIST
// =============================================================================

void	reverse_list(t_dlist **start)
{
	t_dlist	*prev_node;
	t_dlist	*temp_node;
	t_dlist	*curr_node;

	if (*start != NULL)
	{
		prev_node = *start;
		temp_node = *start;
		curr_node = (*start)->next;
		prev_node->next = prev_node;
		prev_node->prev = prev_node;
		while (curr_node != *start)
		{
			temp_node = curr_node->next;
			curr_node->next = prev_node;
			prev_node->prev = curr_node;
			(*start)->next = curr_node;
			curr_node->prev = *start;
			prev_node = curr_node;
			curr_node = temp_node;
		}
		*start = prev_node;
	}
}

// =============================================================================
// SWAP NODES
// =============================================================================

void	swap_values(t_dlist *start, int node1, int node2)
{
	int		i;
	int		j;
	int		value;
	t_dlist	*temp;
	t_dlist	*pos1;
	t_dlist	*pos2;

	i = 0;
	temp = start;
	if (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	while (temp != start)
	{
		i++;
		temp = temp->next;
	}
	if (node1 < 1 || node1 > i || node2 < 1 || node2 > i)
		return ;
	pos1 = start;
	pos2 = start;
	j = 0;
	while (++j < node1)
		pos1 = pos1->next;
	j = 0;
	while (++j < node2)
		pos2 = pos2->next;
	value = pos1->data;
	pos1->data = pos2->data;
	pos2->data = value;
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
	printf("First node created.\n");
	mid = create_node(50);
	printf("Second node created.\n");
	end = create_node(100);
	printf("Third node created.\n");

	start->next = mid;
	mid->next = end;
	end->next = start;

	end->prev = mid;
	mid->prev = start;
	start->prev = end;

	insert_back(&start, 150);
	printf("New value |150| inserted back.\n");
	insert_front(&start, -100);
	printf("New value |-100| inserted front.\n");
	insert_front(&start, 2);
	printf("New value |2| inserted front.\n");
	insert_after(&start, 42, 50);
	printf("New value |42| inserted after 50.\n");
	insert_at(&start, 80, 3);
	printf("New value |80| inserted at position 3.\n");

	printf("\n/////////// OG List\n");
	display(start);
	printf("list size:\t|%d|\n", get_len(start));

	del_first(&start);
	printf("First position deleted.\n");
	display(start);
	printf("list size:\t|%d|\n", get_len(start));
	
	del_last(&start);
	printf("Last position deleted.\n");
	display(start);
	printf("list size:\t|%d|\n", get_len(start));

	del_at(&start, 3);
	printf("Position 3n deleted.\n");
	display(start);
	printf("list size:\t|%d|\n", get_len(start));

	swap_values(start, 2, 3);
	printf("Swap position 1 and 2.\n");
	display(start);
	printf("list size:\t|%d|\n", get_len(start));

	// reverse_list(&start);
	// printf("List reversed.\n");
	// display(start);
	// printf("list size:\t|%d|\n", get_len(start));
	// del_all(&start);
	// printf("List empty\n");
	// display(start);
	// printf("list size:\t|%d|\n", get_len(start));

	// search_element(start, 50);
	return (0);
}
