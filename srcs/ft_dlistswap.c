/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:07:17 by harndt            #+#    #+#             */
/*   Updated: 2022/09/23 22:24:20 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlistswap(t_dlist *start, int node1, int node2)
{
	int		i;
	int		j;
	int		value;
	t_dlist	*temp;
	t_dlist	*pos1;
	t_dlist	*pos2;

	i = 0;
	temp = start;
	if (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	while (temp != start)
	{
		i++;
		temp = temp->next;
	}
	if (node1 < 1 || node1 > i || node2 < 1 || node2 > i)
		return ;
	pos1 = start;
	pos2 = start;
	j = 0;
	while (++j < node1)
		pos1 = pos1->next;
	j = 0;
	while (++j < node2)
		pos2 = pos2->next;
	value = pos1->data;
	pos1->data = pos2->data;
	pos2->data = value;
}
