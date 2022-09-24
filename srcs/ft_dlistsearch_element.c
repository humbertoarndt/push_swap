/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistsearch_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:05:32 by harndt            #+#    #+#             */
/*   Updated: 2022/09/24 22:18:21 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dlistsearch_element(t_dlist *start, int value)
{
	int		i;
	int		found;
	t_dlist	*temp;

	i = 0;
	found = 0;
	temp = start;
	if (temp != NULL)
	{
		while (1)
		{
			i++;
			if (temp->data == value)
			{
				found++;
				break ;
			}
			temp = temp->next;
			if (temp == start)
				break ;
		}
		if (found == 1)
			return (i);
	}
	return (-1);
}
