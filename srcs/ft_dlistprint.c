/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:55:52 by harndt            #+#    #+#             */
/*   Updated: 2022/09/23 22:23:34 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlist_print(t_dlist *start)
{
	t_dlist	*temp;
	int		i;

	if (start != NULL)
	{
		i = 0;
		temp = start;
		printf("%d:\t|%d|\n", i++, temp->data);
		temp = temp->next;
		while (temp != start)
		{
			printf("%d:\t|%d|\n", i++, temp->data);
			temp = temp->next;
		}
	}
	else
		printf("List empty\n");
}
