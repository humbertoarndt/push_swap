/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:25:59 by harndt            #+#    #+#             */
/*   Updated: 2022/10/12 17:35:14 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->size)
	{
		ft_putendl_fd("pa", 1);
		stack_push(a, stack_pop(b));
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size)
	{
		ft_putendl_fd("pb", 1);
		stack_push(b, stack_pop(a));
	}
}
