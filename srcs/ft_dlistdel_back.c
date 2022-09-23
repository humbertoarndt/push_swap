/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistdel_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:03:03 by harndt            #+#    #+#             */
/*   Updated: 2022/09/23 22:22:24 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlistdel_back(t_dlist **start)
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
