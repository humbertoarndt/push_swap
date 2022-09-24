# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 00:19:18 by harndt            #+#    #+#              #
#    Updated: 2022/09/24 22:19:22 by harndt           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============================================================================
# VARIABLES
# ==============================================================================

NAME		:=	push_swap
CC			:=	cc
CFLAGS		:=	#-Wall -Werror -Wextra
HEADERS		:=	includes
LIBFT		:=	./libft/libft.a
SRCS		:=	push_swap.c
SRCS		+=	./srcs/ft_dlistreverse.c	./srcs/ft_dlistadd_after.c	\
				./srcs/ft_dlistadd_back.c	./srcs/ft_dlistswap.c		\
				./srcs/ft_dlistdel_front.c	./srcs/ft_dlistprint.c		\
				./srcs/ft_dlistsearch_element.c	./srcs/ft_dlistnew.c	\
				./srcs/ft_dlistadd_front.c	./srcs/ft_dlistadd_at.c		\
				./srcs/ft_dlistdel_back.c	./srcs/ft_dlistget_len.c	\
				./srcs/ft_dlistdel_at.c		./srcs/ft_dlistclear.c
OBJS		:=	$(SRCS:.c=.o)

# ==============================================================================
# COLORS
# ==============================================================================

GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHT			:=	\033[1;37m
EOC			:=	\033[1;0m

# ==============================================================================
# RECIPES
# ==============================================================================

all:		$(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
			@echo "$(WHT)Compiling PUSH SWAP...$(EOC)"
			@$(CC) $(OBJS) $(LIBFT) -o $@
			@echo "$(GREEN)PUSH SWAP build completed.$(EOC)"

$(LIBFT):
			@make -C libft

clean:
			@echo "$(WHT)Removing .o files...$(EOC)"
			@rm -f $(OBJS)
			@make -C libft clean
			@echo "$(GREEN)Clean done.$(EOC)"

fclean:		clean
			@echo "$(WHT)Removing object- and binary -files...$(EOC)"
			@rm -f $(NAME)
			@make -C libft fclean
			@echo "$(GREEN)Fclean done.$(EOC)"

re:			fclean all

#valgrind:

.PHONY:		all clean fclean re valgrind