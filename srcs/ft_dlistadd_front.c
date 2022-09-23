/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:58:29 by harndt            #+#    #+#             */
/*   Updated: 2022/09/23 22:33:25 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlistadd_front(t_dlist **start, int data)
{
	t_dlist	*last;
	t_dlist	*new_node;

	new_node = ft_dlistnew(data);
	last = (*start)->prev;
	new_node->next = *start;
	new_node->prev = last;
	last->next = new_node;
	(*start)->prev = new_node;
	*start = new_node;
}
