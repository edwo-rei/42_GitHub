# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 10:48:27 by edwo-rei          #+#    #+#              #
#    Updated: 2025/11/17 13:45:12 by edwo-rei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
##obligatory compiler (cc is set to clang on these machines)

CFLAGS = -Wall -Wextra -Werror
##Wall & Wextra enable useful warnings (Wextra is stricter, can cause false pos). 
##Werror treats them as errors & compilation fails. -g allows line #s to be 
##included w/ error output in terminal but should be removed for turn-in

NAME = so_long
## usually designates name of output executable file, obligatory

DEPS = so_long.h
##so if a change is made, .c files will recompile(see below)

LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libft_printf.a
GNL = gnl/libft_gnl.a
MLX = mlx/libmlx.a
##macros for archive files for libs used

SRC = $(addprefix src/, main.c parse_map.c validate_path.c render.c utility.c)
## $(addprefix src/) adds that prefix to all the files listed after

OBJ = $(SRC:.c=.o) 

INCLUDE = -L ./libft -lft -L ./gnl -lft_gnl -L ./ft_printf -lft_printf -L ./mlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
## -L = linker option; "-L ./ft_printf" tells linker to linker to look in that dir 
## when searchin for libs; -l strips "lib" prefix & .a/.so suffix, so 
## -lftprintf = libftprintf.a/libftprintf.so. "-L/usr/lib" indicates where system libraries are. "-Imlx" specifies that the compiler should look in mlx/ for header files, MAY NOT BE NECESSARY. "-lXext" and "-lX11" indicates where graphics libraries needed by MiniLibX are. "-lm" links the math lib & "-lx" links the zlib compression library. Found these include flags in the harm-smits MiniLibX guide

## first targ defined invoked when typing just "make", program to be built
all: $(NAME)

## All dependencies needed built in that order w/ this step. Need to use the archive
##files to check if they have been built already, not phony targets - which would
##cause them to get rebuilt each time the make cmd is given, b/c it would not
##register that those dependencies were already up to date
## Must use $(OBJ) and not $< b/c will only compile the 1st obj file (main.o)
$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(GNL) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $@

## prereqs (right of targ) must be up to date (account for changes to .h)
%.o: %.c $(DEPS)
	 $(CC) $(CFLAGS) -c -o $@ $<
	 ## $@ is target, $< is 1st DEP, -c just makes .o (& not executable). -Imlx adds the directory where mlx.h is locate, MAY NOT BE NECESSARY

## compile MiniLibX iot use it
$(MLX):
	make -C mlx/
	
$(FT_PRINTF):
	make -C ft_printf/

$(GNL):
	make -C gnl/
	
$(LIBFT):
	make -C libft/

clean:
	cd src/ && rm -f *.o
	make clean -C libft/
	make clean -C gnl/
	make clean -C ft_printf/
	make clean -C mlx/

## previously, clean was a dependency of fclean, but that led to rm -f *.o being
## executed twice on libft/ & printf/, so changed it
## mlx doesn't have an fclean rule
fclean:
	rm  -f $(NAME)
	cd src/ && rm -f *.o
	make fclean -C libft/
	make fclean -C gnl/
	make fclean -C ft_printf/
	make clean -C mlx/

re: fclean all

##don't generate files, avoid confusion w/ existing
.PHONY: all clean fclean re
