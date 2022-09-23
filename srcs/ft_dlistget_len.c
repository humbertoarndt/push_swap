/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistget_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:00:18 by harndt            #+#    #+#             */
/*   Updated: 2022/09/23 22:23:07 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dlistget_len(t_dlist *start)
{
	int		i;
	t_dlist	*temp;

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
	return (i);
}
