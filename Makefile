# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 20:55:32 by ishenriq          #+#    #+#              #
#    Updated: 2023/11/04 16:58:27 by ishenriq         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #


#Name
NAME = libft.a

#Compiler and flags
CC = cc
CFLAGS =  -Wall -Wextra -Werror

#arquivos e objetos
PT_C = ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strmapi.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c

PT_C_B = ft_lstadd_back_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstlast_bonus.c \
ft_lstmap_bonus.c \
ft_lstnew_bonus.c \
ft_lstsize_bonus.c

INCLUDES = libft.h

OBJS = $(PT_C:.c=.o)
OBJS_BONUS = $(PT_C_B:.c=.o)

ifdef	WITH_BONUS
	OBJS += $(OBJS_BONUS)
endif

#Rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rc -s $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS_BONUS)
	@make WITH_BONUS=TRUE --no-print-directory

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

