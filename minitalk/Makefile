# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 14:05:16 by edwo-rei          #+#    #+#              #
#    Updated: 2025/10/01 17:47:07 by edwo-rei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc ##obligatory compiler (cc is set to clang on these machines)
CFLAGS = -Wall -Wextra -Werror ##Wall & Wextra enable useful warnings (Wextra is stricter, can cause false pos). Werror treats them as errors & compilation fails
NAME = minitalk ##designates name of output executable file, obligatory
## LIBS = libft/ ##works like this but must check example code
DEPS = push_swap.h ##so if a change is made, .c files will recompile(see below)
SRC = client.c server.c 
OBJ = $(SRC:.c=.o) 
INCLUDE = -L ./libft -lft -L ./ft_printf -lftprintf ## -L = linker option; "-L ./libft" tells linker to linker to look in that dir when searchin for libs; -l strips "lib" prefix & .a/.so suffix, so -lft = libft.a/libft.so

all: $(NAME) ##first targ defined invoked when typing just "make", program to be built

$(NAME): server client ##make the libft.a w/ libft functions; -C flag means cdto directory indicated, then cd back after
	   $(CC) $(CFLAGS) -o $@ $^ $(INCLUDE)

%.o: %.c $(DEPS) ##prereqs (right of targ) must be up to date (account for changes to .h)
	 $(CC) $(CFLAGS) -c -o $@ $< ##$@ is target, $< is 1st DEP, -c just makes .o (& not executable)

server: server.o libft ft_printf
	$(CC) $(CFLAGS) -o $@ $< $(INCLUDE)

client: client.o libft ft_printf
	$(CC) $(CFLAGS) -o $@ $< $(INCLUDE)

libft:
	make -C libft/

ft_printf:
	make -C ft_printf/

clean:
	rm -f *.o
	make clean -C libft/
	make clean -C ft_printf/
## $(MAKE) macro expands to prog. running my Makefile and propogates command line flags

fclean: clean
	 rm -f $(NAME) server client
	 make fclean -C libft/
	 make fclean -C ft_printf/

re: fclean all

.PHONY: all libft ft_printf clean fclean re ##don't generate files, avoid confusion w/ existing
