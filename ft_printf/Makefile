# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 16:50:29 by edwo-rei          #+#    #+#              #
#    Updated: 2025/05/21 19:56:00 by edwo-rei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
DEPS = ft_printf.h
SRC = ft_printf.c ft_printchar.c ft_printstr.c ft_printint.c ft_printunint.c \
      ft_printhex.c ft_printptr.c
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
