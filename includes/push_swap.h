/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:50:37 by harndt            #+#    #+#             */
/*   Updated: 2022/10/12 16:57:39 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// =============================================================================
// LOCAL LIBRARIES
// =============================================================================

# include "usage.h"
# include "../libft/libft.h"

// =============================================================================
// EXTERNAL LIBRARIES
// =============================================================================

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

// =============================================================================
// DEFINES
// =============================================================================

# define MAX +2147483647
# define MIN -2147483648

// =============================================================================
// STRUCTS
// =============================================================================

typedef struct s_stack
{
	t_list	*head;
	int		size;
}				t_stack;

// =============================================================================
// FUNCTIONS
// =============================================================================

/**
 * @brief Prints each value on the stack into the terminal.
 * @param t_stack The stack to be printed.
**/
void	print_stack(t_stack	*stack);

/**
 * @brief Pushs a new value into a stack and increases its size.
 * @param t_stack The stack to receive a new value.
 * @param void The new value.
**/
void	stack_push(t_stack *stack, void *content);

/**
 * @brief Pops a value from the given stack.
 * @param t_stack The stack to be poped.
**/
void	*stack_pop(t_stack *stack);

/**
 * @brief Shifts up all ellements from the stack by 1.
 * @param t_stack The stack to be shifted.
 * @param void The node content.
**/
void	stack_shift(t_stack *stack, void *content);

/**
 * @brief Shifts down all ellements from the stack by 1.
 * @param t_stack The stack to be shifted.
 * @return The unshifted stack.
**/
void	*stack_unshift(t_stack *stack);

/**
 * @brief Founds the median value at the given stack.
 * @param t_stack The stack to be calculated.
 * @return The median value.
**/
int		stack_median(t_stack *stack);

/**
 * @brief Swaps the first to position a the given stack.
 * @param t_stack The stack to be swapped.
**/
void	swap(t_stack *stack);

/**
 * @brief Swap the first 2 elements at the top of stack a.
 Do nothing if there is only one or no elements.
 * @param t_stack The stack to be swapped.
 * @param t_stack The stack to be swapped.
**/
void	sa(t_stack *a, t_stack *b);

/**
 * @brief Swap the first 2 elements at the top of stack b.
 Do nothing if there is only one or no elements.
 * @param t_stack The stack to be swapped.
 * @param t_stack The stack to be swapped.
**/
void	sb(t_stack *a, t_stack *b);

/**
 * @brief Do sa and sb at the same time.
 * @param t_stack The stack to be swapped.
 * @param t_stack The stack to be swapped.
**/
void	ss(t_stack *a, t_stack *b);

/**
 * @brief Take the first element at the top of b and put it a the top o a.
 Do nothing if b is empty.
 * @param t_stack The stack to be popped/pushed.
 * @param t_stack The stack to be popped/pushed.
**/
void	pa(t_stack *a, t_stack *b);

/**
 * @brief Take the first element at the top of a and put it a the top o b.
 Do nothing if a is empty.
 * @param t_stack The stack to be popped/pushed.
 * @param t_stack The stack to be popped/pushed.
**/
void	pb(t_stack *a, t_stack *b);

/**
 * @brief Rotates the given stack.
 * @param t_stack The stack to be up shifted.
**/
void	rotate(t_stack *stack);

/**
 * @brief Shift up all elements of stack a by 1.
 * @param t_stack to be shifted.
 * @param t_stack to be shifted.
**/
void	ra(t_stack *a, t_stack *b);

/**
 * @brief Shift up all elements of stack b by 1.
 * @param t_stack to be shifted.
 * @param t_stack to be shifted.
**/
void	rb(t_stack *a, t_stack *b);

/**
 * @brief Do ra and rb at the same time.
**/
void	rr(t_stack *a, t_stack *b);

/**
 * @brief Reverse rotates the given stack.
 * @param t_stack The stack to be up shifted.
**/
void	reverse_rotate(t_stack *stack);

/**
 * @brief Shift down all elements of stack a by 1.
 * @param t_stack to be shifted.
 * @param t_stack to be shifted.
**/
void	rra(t_stack *a, t_stack *b);

/**
 * @brief Shift down all elements of stack b by 1.
 * @param t_stack to be shifted.
 * @param t_stack to be shifted.
**/
void	rrb(t_stack *a, t_stack *b);

/**
 * @brief Do rra and rrb at the same time.
**/
void	rrr(t_stack *a, t_stack *b);

/**
 * @brief Checks if a list is sorted.
 * @param t_list The list to be checked.
 * @return True if the list is sorted; False if the list is not.
**/
t_bool	is_sorted(t_list *list);

/**
 * @brief Gets the highest value in a list.
 * @param t_list The list to be searched.
 * @return The highest value.
**/
void	*get_max(t_list *list);

/**
 * @brief Gets the lowest value in a list.
 * @param t_list The list to be searched.
 * @return The lowest value.
**/
void	*get_min(t_list *list);

/**
 * @brief Sorts lists with size less than 4.
 * @param t_stack The stack to be sorted.
 * @param t_stack The stack to be sorted.
**/
void	sort_small(t_stack *a, t_stack *b);

/**
 * @brief Sorts lists with size bigger than 3 and less than 6.
 * @param t_stack The stack to be sorted.
 * @param t_stack The stack to be sorted.
**/
void	sort_medium(t_stack *a, t_stack *b);

/**
 * @brief Sorts large lists.
 * @param t_stack The stack to be sorted.
 * @param t_stack The stack to be sorted.
**/
void	sort_large(t_stack *a, t_stack *b);

#endif