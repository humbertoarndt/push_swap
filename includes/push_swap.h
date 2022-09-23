/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:50:37 by harndt            #+#    #+#             */
/*   Updated: 2022/09/23 22:55:47 by harndt           ###   ########.fr       */
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
typedef struct s_dlist
{
	struct s_dlist	*prev;
	int				data;
	struct s_dlist	*next;
}					t_dlist;

// =============================================================================
// FUNCTIONS
// =============================================================================

/**
 * @brief Creates and insert a new node of value data1 after node with value
 *  data2.
 * 
 * @param start Reference to the head of the list.
 * @param data1 The new value to be included.
 * @param data2 The value to use as postion reference.
 */
void	ft_dlistadd_after(t_dlist **start, int data1, int data2);

/**
 * @brief Creates and insert a new node a the given position.
 * 
 * @param start Reference to the head of the list.
 * @param data The new data to insert.
 * @param position The given position.
 */
void	ft_dlistadd_at(t_dlist **start, int data, int position);

/**
 * @brief Creates and insert a new node at the last position.
 * 
 * @param start Reference to the head of the list.
 * @param data The new data to insert.
 */
void	ft_dlistadd_back(t_dlist **start, int data);

/**
 * @brief Creates and insert a new node at the beginning of the list.
 * 
 * @param start Reference to the head of the list.
 * @param data The new data to insert.
 */
void	ft_dlistadd_front(t_dlist **start, int data);

/**
 * @brief Clear every node from the list.
 * 
 * @param start Referente to the head of the list.
 */
void	ft_dlistclear(t_dlist **start);

/**
 * @brief Removes a node at the given postion.
 * 
 * @param start Reference to the head of the list.
 * @param position The position to remove.
 */
void	ft_dlistdel_at(t_dlist **start, int position);

/**
 * @brief Removes the last node from the list.
 * 
 * @param start Reference to the head of the list.
 */
void	ft_dlistdel_back(t_dlist **start);

/**
 * @brief Removes the first node from the list.
 * 
 * @param start Reference to the head of the list.
 */
void	ft_dlistdel_front(t_dlist **start);

/**
 * @brief Gets the lenght from the given list.
 * 
 * @param start Reference to the head of the list.
 * @return int The list lenght.
 */
int		ft_dlistget_len(t_dlist *start);

/**
 * @brief Creates a new node.
 * 
 * @param data The value to be stored.
 * @return t_dlist* The created node.
 */
t_dlist	*ft_dlistnew(int data);

/**
 * @brief Prints all elemtens from the list.
 * 
 * @param start Reference to the head of the list.
 */
void	ft_dlist_print(t_dlist *start);

/**
 * @brief Reverses the list.
 * 
 * @param start reference to the head of the list.
 */
void	ft_dlistreverse(t_dlist **start);

/**
 * @brief Searchs if an elemente exists on the list.
 * 
 * @param start Reference to the head of the list.
 * @param value The value to search.
 */
void	ft_dlistsearch_element(t_dlist *start, int value);

/**
 * @brief Swaps the position from two nodes on the list.
 * 
 * @param start Reference to the head of the list.
 * @param node1 The value of the first node to be swaped.
 * @param node2 The value of the second node to be swaped.
 */
void	ft_dlistswap(t_dlist *start, int node1, int node2);

#endif