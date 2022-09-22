# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 00:19:18 by harndt            #+#    #+#              #
#    Updated: 2022/09/09 00:59:39 by harndt           ###   ########.fr        #
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
			@$(CC) $(OBJS) $(LINKS) $(LIBFT) -o $@
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