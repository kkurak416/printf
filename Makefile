# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 14:55:51 by kkurowsk          #+#    #+#              #
#    Updated: 2025/01/09 14:56:55 by kkurowsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
HEADER  = ft_printf.h

NAME    = libftprintf.a

SRC     = ft_printf.c print_char.c print_string.c print_pointer.c print_int.c print_hex.c print_uint.c

OBJS    = $(SRC:.c=.o)



CC      = cc
CFLAGS  = -Wall -Werror -Wextra -I$(LIB_PATH)
LIB_PATH = ../libft
LIBFT   = $(LIB_PATH)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIB_PATH) all

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -I./ $< -o $@

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIB_PATH) clean

re: fclean all

.PHONY: all clean fclean re


