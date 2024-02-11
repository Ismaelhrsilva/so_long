# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 20:08:54 by ishenriq          #+#    #+#              #
#    Updated: 2024/02/11 15:43:53 by ishenriq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
NAME_BONUS = so_long_bonus
CFLAGS	:= -g3
#CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3 -O3
CC	:= cc
LIBMLX	:= lib/MLX42/
PRINTF	:= lib/printf/
LIBFT	:= lib/libft/
GNL	:= lib/gnl/
BUILD_DIR = objects/
MKDIR  := mkdir -p

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT) -I $(PRINTF) $(LIBS) -I $(GNL)

LIBS 	:= $(LIBMLX)build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)libft.a \
	-lm $(PRINTF)libftprintf.a

LDFLAGS	:= $(HEADERS) $(LIBS)

SRCS += $(addprefix src/mandatory/, close.c \
	construct_image.c \
	hook.c \
	init_functions.c \
	main.c \
	map.c \
	so_long.c \
	utils.c \
	validations.c)

SRCS_BONUS	= $(wildcard src/bonus/*.c)

OBJS	+=  $(SRCS:%.c=$(BUILD_DIR)%.o)
OBJS_BONUS	+= $(SRCS_BONUS:%.c=$(BUILD_DIR)%.o)

ifdef   WITH_BONUS
        NAME = $(NAME_BONUS)
		OBJS = $(OBJS_BONUS)
endif

define create_dir
	$(MKDIR) $(dir $@)
endef

define bonus
	$(make) WITH_BONUS=TRUE
endef

all: libmlx libft printf $(NAME)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)build && make -C $(LIBMLX)build -j4

libft:
	@make -C $(LIBFT)

printf:
	@make -C $(PRINTF)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)


bonus:
	$(call bonus)

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

.PHONY: all, clean, fclean, re, libmlx, libft, printf, bonus
.DEFAULT_GOAL := all
