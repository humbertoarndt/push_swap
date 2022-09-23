/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistreverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:06:32 by harndt            #+#    #+#             */
/*   Updated: 2022/09/23 22:23:52 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlistreverse(t_dlist **start)
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
