/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistadd_after.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:59:27 by harndt            #+#    #+#             */
/*   Updated: 2022/09/23 22:32:45 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlistadd_after(t_dlist **start, int data1, int data2)
{
	t_dlist	*next;
	t_dlist	*temp;
	t_dlist	*new_node;

	new_node = ft_dlistnew(data1);
	temp = *start;
	while (temp->data != data2)
		temp = temp->next;
	next = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	new_node->next = next;
	next->prev = new_node;
}
