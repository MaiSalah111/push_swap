# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 11:08:32 by mualkhid          #+#    #+#              #
#    Updated: 2024/03/23 17:10:12 by maiahmed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
NAME_BONUS := checker


SRCS := 	push_swap.c \
			errors_handling.c	\
			push_a_to_b.c \
			push_b_to_a.c \
			push_operations.c \
			rev_rotate_operations.c \
			rotate_operations.c \
			stack_sorting.c \
			sort_3_nums.c \
			split.c \
			stack_prep.c \
			push_swap_utils.c \
			swap_operations.c \

SRCSB := checker.c \
			checker_utils.c \
			errors_handling.c	\
			push_a_to_b.c \
			push_b_to_a.c \
			push_operations.c \
			rev_rotate_operations.c \
			rotate_operations.c \
			stack_sorting.c \
			sort_3_nums.c \
			split.c \
			stack_prep.c \
			push_swap_utils.c \
			swap_operations.c \
			get_next_line.c \
			get_next_line_utils.c \


OBJS := $(SRCS:.c=.o)
OBJSB := $(SRCSB:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
RM := rm -f

LIBFT := libft/libft.a
PRINTF := ft_printf/libftprintf.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)


bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJSB) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJSB) $(LIBFT) $(PRINTF)



clean:
	make clean -C libft
	make clean -C ft_printf
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	$(RM) $(NAME) $(NAME_BONUS)


re: fclean all

.PHONY: all clean fclean re bonus
