/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:57:34 by harndt            #+#    #+#             */
/*   Updated: 2022/09/23 22:33:14 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlistadd_back(t_dlist **start, int data)
{
	t_dlist	*last;
	t_dlist	*new_node;

	new_node = ft_dlistnew(data);
	last = (*start)->prev;
	new_node->prev = last;
	new_node->next = *start;
	(*start)->prev = new_node;
	last->next = new_node;
}
