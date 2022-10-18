/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:57:32 by harndt            #+#    #+#             */
/*   Updated: 2022/10/14 02:31:29 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Prints a message and ends the program.
 * @param msg The message to be printed.
 */
static void	usage(char *msg)
{
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

/**
 * @brief Checks if two values are equal.
 * @param void The first value to compare.
 * @param void The second value to compare.
 * @return True if the values are equal; False if they are not.
**/
static t_bool	is_equal(void *content, void *data)
{
	return (*(int *)content == *(int *)data);
}

/**
 * @brief Checks if the received arguments are valid. By:
 Checking if the argument exists.
 Checking if the arguments are int.
 Checking if the arguments do not surpasses the MAX/MIN int values.
 Checking if there is a duplicated values.
 If the argument is valid, pushes the value into the given stack.
 * @param int The input index.
 * @param char The arguments received.
 * @param t_stack The stack to store the receivd values.
 * @return True if the arguments are valid; False if they are not.
**/
static t_bool	is_valid(int argc, char **argv, t_stack *stack)
{
	long	temp;
	int		*content;

	if (!argc)
		return (FALSE);
	while (argc)
	{
		if (!ft_isnum(argv[argc - 1]))
			usage(LST_INT);
		temp = ft_atol(argv[argc-- -1]);
		if (temp > MAX || temp < MIN)
			usage(LST_MAX);
		content = (int *) malloc(sizeof(*content));
		if (!content)
			return (FALSE);
		*content = (int)temp;
		if (stack->head && ft_lstfind(stack->head, content, is_equal))
			usage (LST_DBL);
		stack_push(stack, content);
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a = (t_stack){NULL, 0};
	b = (t_stack){NULL, 0};
	if (argc == 1)
		usage(USG);
	if (!is_valid(argc - 1, &argv[1], &a))
		usage(ERR);
	if (!is_sorted(a.head))
	{
		if (a.size < 4)
			sort_small(&a, &b);
		else if (a.size < 6)
			sort_medium(&a, &b);
		else
			sort_large(&a, &b);
	}
	ft_lstclear(&a.head, free);
	return (0);
}
