/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistdel_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:03:47 by harndt            #+#    #+#             */
/*   Updated: 2022/09/23 22:22:17 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlistdel_at(t_dlist **start, int position)
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
