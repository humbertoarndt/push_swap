/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistadd_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:01:26 by harndt            #+#    #+#             */
/*   Updated: 2022/09/23 22:34:15 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlistadd_at(t_dlist **start, int data, int position)
{
	int		i;
	t_dlist	*temp;
	t_dlist	*new_node;

	i = 0;
	new_node = ft_dlistnew(data);
	temp = *start;
	if (position < 1 || position > ft_dlistget_len(*start))
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
