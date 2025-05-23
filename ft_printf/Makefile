# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 16:50:29 by edwo-rei          #+#    #+#              #
#    Updated: 2025/05/23 12:57:06 by edwo-rei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc ##obligatory compiler (cc is set to clang on these machines)
CFLAGS = -Wall -Wextra -Werror ##Wall & Wextra enable useful warnings (Wextra is stricter, can cause false pos). Werror treats them as errors & compilation fails
NAME = libftprintf.a ##designates name of output archive file, obligatory
DEPS = ft_printf.h ##so if a change is made, .c files will recompile(see below)
SRC = ft_printf.c ft_printchar.c ft_printstr.c ft_printint.c ft_printunint.c \
      ft_printhex.c ft_printptr.c
OBJ = $(SRC:.c=.o) 

all: $(NAME) ##first targ defined invoked when typing just "make", program to be built
$(NAME): $(OBJ)
	 ar -crs $@ $^ ##creates archive file, c: creates file, r: add files to file (w/ replace), s: create index of files inside lib file
%.o: %.c $(DEPS) ##prereqs (files to right of targ) must be up to date (account for changes to .h)
	 $(CC) $(CFLAGS) -c -o $@ $< ##$@ is target, $< is 1st DEP, -c just makes .o (& not executable)
clean:
	rm -f *.o
fclean: clean
	 rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re ##don't generate files, avoid confusion w/ existing
