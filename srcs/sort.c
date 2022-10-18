/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:43:01 by harndt            #+#    #+#             */
/*   Updated: 2022/10/12 16:59:29 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = *(int *)get_min(a->head);
	max = *(int *)get_max(a->head);
	while (!is_sorted(a->head))
	{
		if (*(int *)a->head->content == max
			&& *(int *)a->head->next->content == min)
			ra(a, b);
		else if ((*(int *)a->head->content == min
				&& *(int *)a->head->next->content == max)
			|| (*(int *)a->head->content > *(int *)a->head->next->content))
			sa(a, b);
		else
			rra(a, b);
	}
}

/**
 * @brief Breaks the list by its median.
 * @param t_stack The stack to be handled.
 * @param t_stack The auxiliar stack to be handled.
 * @return 
**/
static void	partition_medium(t_stack *a, t_stack *b)
{
	int	median;
	int	middle;

	median = stack_median(a);
	middle = a->size / 2;
	while (middle)
	{
		if (*(int *)a->head->content < median)
		{
			middle--;
			pb(a, b);
		}
		else
			ra(a, b);
	}
}

void	sort_medium(t_stack *a, t_stack *b)
{
	partition_medium(a, b);
	sort_small(a, b);
	if (is_sorted(b->head))
		sb(a, b);
	while (b->size)
		pa(a, b);
}

/**
 * @brief Indexes the positions by value in a stack.
 * @param t_stack The stack to be indexed.
**/
static void	index_stack(t_stack *stack)
{
	int		i;
	t_list	*list;
	t_list	*sorted;
	t_list	*temp_sorted;

	sorted = ft_lstdup_int(stack->head);
	ft_lstsort(sorted, 0, stack->size - 1);
	list = stack->head;
	while (list)
	{
		temp_sorted = sorted;
		i = 0;
		while (i < stack->size)
		{
			if (*(int *)list->content == *(int *)temp_sorted->content)
			{
				*(int *)list->content = i;
				break ;
			}
			temp_sorted = temp_sorted->next;
			i++;
		}
		list = list->next;
	}
	ft_lstclear(&sorted, free);
}

void	sort_large(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	num;
	int	size;

	index_stack(a);
	size = a->size;
	i = 0;
	while (!is_sorted(a->head))
	{
		j = 0;
		while (j < size)
		{
			num = *(int *)a->head->content;
			if ((num >> i) & 1)
				ra(a, b);
			else
				pb(a, b);
			j++;
		}
		while (b->size)
			pa(a, b);
		i++;
	}
}
