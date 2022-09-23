/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:04:33 by harndt            #+#    #+#             */
/*   Updated: 2022/09/23 22:21:54 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlistclear(t_dlist **start)
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
