# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 20:08:54 by ishenriq          #+#    #+#              #
#    Updated: 2024/01/03 21:55:24 by ishenriq         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
CC	:= cc
LIBMLX	:= ./lib/MLX42
PRINTF	:= ./lib/printf
LIBFT	:= ./lib/libft
GNL	:= ./lib/gnl

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT) -I $(PRINTF) $(LIBS) -I $(GNL)


LIBS 	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a \
	-lm $(PRINTF)/libftprintf.a

LDFLAGS	:= $(HEADERS) $(LIBS)

SRCS	:= $(wildcard ./src/*.c)

OBJS	:= ${SRCS:.c=.o}

all: libmlx libft printf $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

printf:
	@make -C $(PRINTF)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean
	@make -C $(PRINTF) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make -C $(LIBFT) fclean
	@make -C $(PRINTF) fclean

re: clean all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS) ./include

.PHONY: all, clean, fclean, re, libmlx, libft, printf
