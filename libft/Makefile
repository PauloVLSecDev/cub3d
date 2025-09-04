# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 14:49:20 by pvitor-l          #+#    #+#              #
#    Updated: 2025/03/05 16:27:47 by pvitor-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

FILE = ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isprint.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_memcpy.c \
	ft_memset.c \
	ft_memmove.c \
	ft_bzero.c \
	ft_strlen.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_memchr.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_memcmp.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putendl_fd.c \
	ft_putstr_fd.c \
	ft_putnbr.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_substr.c \
	ft_strtrim.c \
	ft_split.c \
	ft_striteri.c \
	ft_hexa.c \
	ft_put_unsi.c \
	ft_printf.c \
	free_array.c \
	get_next_line.c 

OBJS = $(FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean

	rm -f $(NAME)

re: fclean $(NAME)

PHONY: all clean fclean re
