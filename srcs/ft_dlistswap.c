/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:07:17 by harndt            #+#    #+#             */
/*   Updated: 2022/09/24 22:18:55 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlistswap(t_dlist *start, int node1, int node2)
{
	int		len;
	int		temp;
	t_dlist	*swap;
	t_dlist	*pos1;
	t_dlist	*pos2;

	swap = start;
	len = ft_dlistget_len(start);
	if (node1 < 1 || node1 > len || node2 < 1 || node2 > len)
		return ;
	pos1 = start;
	pos2 = start;
	temp = 0;
	while (++temp < node1)
		pos1 = pos1->next;
	temp = 0;
	while (++temp < node2)
		pos2 = pos2->next;
	temp = pos1->data;
	pos1->data = pos2->data;
	pos2->data = temp;
}
