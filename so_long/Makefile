# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 10:48:27 by edwo-rei          #+#    #+#              #
#    Updated: 2025/11/12 14:19:23 by edwo-rei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
##obligatory compiler (cc is set to clang on these machines)

CFLAGS = -Wall -Wextra -Werror -g -v
##Wall & Wextra enable useful warnings (Wextra is stricter, can cause false pos). Werror treats them as errors & compilation fails. -g allows line #s to be included w/ error output in terminal but should be removed for turn-in

NAME = so_long
## usually designates name of output executable file, obligatory

DEPS = so_long.h
##so if a change is made, .c files will recompile(see below)


SRC = main.c parse_map.c validate_path.c render.c utility.c

OBJ = $(SRC:.c=.o) 

INCLUDE = -L ./libft -lft -L ./gnl -lft_gnl -L ./ft_printf -lft_printf -L ./mlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
## -L = linker option; "-L ./ft_printf" tells linker to linker to look in that dir 
## when searchin for libs; -l strips "lib" prefix & .a/.so suffix, so 
## -lftprintf = libftprintf.a/libftprintf.so. "-L/usr/lib" indicates where system libraries are. "-Imlx" specifies that the compiler should look in mlx/ for header files, MAY NOT BE NECESSARY. "-lXext" and "-lX11" indicates where graphics libraries needed by MiniLibX are. "-lm" links the math lib & "-lx" links the zlib compression library. Found these include flags in the harm-smits MiniLibX guide

## first targ defined invoked when typing just "make", program to be built
all: $(NAME)

## All dependencies needed built in that order w/ this step
## Must use $(OBJ) and not $< b/c will only compile the 1st obj file (main.o)
$(NAME): $(OBJ) mlx ft_printf gnl libft
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $@

## prereqs (right of targ) must be up to date (account for changes to .h)
%.o: %.c $(DEPS)
	 $(CC) $(CFLAGS) -Imlx -c -o $@ $<
	 ## $@ is target, $< is 1st DEP, -c just makes .o (& not executable). -Imlx adds the directory where mlx.h is locate, MAY NOT BE NECESSARY

## compile MiniLibX iot use it
mlx:
	make -C mlx/
	
ft_printf:
	make -C ft_printf/

gnl:
	make -C gnl/
	
libft:
	make -C libft/

clean:
	rm -f *.o
	make clean -C libft/
	make clean -C gnl/
	make clean -C ft_printf/
	make clean -C mlx/

## previously, clean was a dependency of fclean, but that led to rm -f *.o being
## executed twice on libft/ & printf/, so changed it
## mlx doesn't have an fclean rule
fclean:
	rm  -f *.o $(NAME)
	make fclean -C libft/
	make fclean -C gnl/
	make fclean -C ft_printf/
	make clean -C mlx/

re: fclean all

##don't generate files, avoid confusion w/ existing
.PHONY: all mlx ft_printf gnl libft clean fclean re
