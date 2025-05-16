# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 16:50:29 by edwo-rei          #+#    #+#              #
#    Updated: 2025/05/16 16:58:56 by edwo-rei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
DEPS = libftprintf.h
SRC = ft_printf.c
OBJ = $(SRC:.c=.o) 

all: $(NAME)
$(NAME): $(OBJ)
	 ar -crs $@ $^
%.o: %.c $(DEPS)
	 $(CC) $(CFLAGS) -c -o $@ $<
clean:
	rm -f *.o
fclean: clean
	 rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
