/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:57:32 by harndt            #+#    #+#             */
/*   Updated: 2022/09/24 22:31:05 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Prints a message and ends the program.
 * 
 * @param msg The message to be printed.
 */
static void	usage(char *msg)
{
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

static t_dlist check(int argc, char **argv)
{
	long	tmp;
	t_dlist	list;

	while (argc -1)
	{
		if (ft_isnum(argv[argc -1]) == 0)
			usage(LST_INT);
		tmp = ft_atol(argv[argc-- -1]);
		if (tmp > MAX)
			usage(LST_MAX);
		if (tmp < MIN)
			usage(LST_MIN);
	}
	return (list);
}

int	main(int argc, char **argv)
{
	t_dlist	list;

	if (argc == 1)
		usage(USG);
	list = check(argc, argv);
	// while (argc -1)
	// 	{
	// 		if (ft_isnum(argv[argc -1]) == 0)
	// 			usage(LST_INT);
	// 		tmp = ft_atol(argv[argc-- -1]);
	// 		if (tmp > MAX)
	// 			usage(LST_MAX);
	// 		if (tmp < MIN)
	// 			usage(LST_MIN);
	// 	}
	ft_printf("Tudo ok!\n");
	return (0);
}
