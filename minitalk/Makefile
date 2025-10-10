# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 14:05:16 by edwo-rei          #+#    #+#              #
#    Updated: 2025/10/10 13:19:47 by edwo-rei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
##obligatory compiler (cc is set to clang on these machines)

CFLAGS = -Wall -Wextra -Werror -g
##Wall & Wextra enable useful warnings (Wextra is stricter, can cause false pos). Werror treats them as errors & compilation fails. -g allows line #s to be included w/ error output in terminal

NAME = minitalk
## usually designates name of output executable file (but not in this case), obligatory

DEPS = minitalk.h
##so if a change is made, .c files will recompile(see below)

SRC = client.c server.c 

OBJ = $(SRC:.c=.o) 

INCLUDE = -L ./libft -lft -L ./ft_printf -lftprintf
## -L = linker option; "-L ./libft" tells linker to linker to look in that dir when searchin for libs; -l strips "lib" prefix & .a/.so suffix, so -lft = libft.a/libft.so

## first targ defined invoked when typing just "make", program to be built
all: $(NAME)

## all dependencies needed for minitalk built in that order w/ this step
$(NAME): $(OBJ) libft ft_printf server client

## prereqs (right of targ) must be up to date (account for changes to .h)
%.o: %.c $(DEPS)
	 $(CC) $(CFLAGS) -c -o $@ $<
	 ## $@ is target, $< is 1st DEP, -c just makes .o (& not executable)

## if you want to just build server, will need to build prereqs one by one
server:
	$(CC) $(CFLAGS) server.o -o $@ $(INCLUDE)

## same as for server
client:
	$(CC) $(CFLAGS) client.o -o $@ $(INCLUDE)

libft:
	make -C libft/

ft_printf:
	make -C ft_printf/

clean:
	rm -f *.o
	make clean -C libft/
	make clean -C ft_printf/

## previously, clean was a dependency of fclean, but that led to rm -f *.o being
## executed twice on libft/ & printf/, so changed it
fclean:
	rm  -f *.o server client
	make fclean -C libft/
	make fclean -C ft_printf/

re: fclean all

##don't generate files, avoid confusion w/ existing
.PHONY: all libft ft_printf clean fclean re
