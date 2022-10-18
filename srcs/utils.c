/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:39:27 by harndt            #+#    #+#             */
/*   Updated: 2022/10/11 00:31:00 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack	*stack)
{
	t_list	*temp;

	if (!stack)
		return ;
	temp = stack->head;
	while (temp)
	{
		ft_printf("|%d|\n", *(int *)temp->content);
		temp = temp->next;
	}
}

t_bool	is_sorted(t_list *list)
{
	if (!list)
		return (FALSE);
	while (list->next)
	{
		if (*(int *)list->content > *(int *)list->next->content)
			return (FALSE);
		list = list->next;
	}
	return (TRUE);
}

void	*get_max(t_list *list)
{
	void	*max;

	if (!list)
		return (NULL);
	max = list->content;
	while (list)
	{
		if (*(int *)list->content > *(int *)max)
			max = list->content;
		list = list->next;
	}
	return (max);
}

void	*get_min(t_list *list)
{
	void	*min;

	if (!list)
		return (NULL);
	min = list->content;
	while (list)
	{
		if (*(int *)list->content < *(int *)min)
			min = list->content;
		list = list->next;
	}
	return (min);
}
