/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistdel_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:02:13 by harndt            #+#    #+#             */
/*   Updated: 2022/09/23 22:22:40 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlistdel_front(t_dlist **start)
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
