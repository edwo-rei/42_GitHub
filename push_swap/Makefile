# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 19:36:00 by edwo-rei          #+#    #+#              #
#    Updated: 2025/09/26 11:10:20 by edwo-rei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc ##obligatory compiler (cc is set to clang on these machines)
CFLAGS = -Wall -Wextra -Werror -g ##Wall & Wextra enable useful warnings (Wextra is stricter, can cause false pos). Werror treats them as errors & compilation fails
NAME = push_swap ##designates name of output archive file, obligatory
LIBS = libft/ ##works like this but must check example code
DEPS = push_swap.h ##so if a change is made, .c files will recompile(see below)
SRC = cost_calculations.c cost_calculations_1.c create_stack.c \
      position_stacks.c push.c push_swap.c reverse_rotate.c rotate.c sort.c \
	swap.c tools.c tools_1.c tools_2.c validate_input.c
OBJ = $(SRC:.c=.o) 
INCLUDE = -L ./libft -lft

all: $(NAME) ##first targ defined invoked when typing just "make", program to be built
$(NAME): $(OBJ)
	   make -C $(LIBS)
	   $(CC) $(CFLAGS) -o $@ $^ $(INCLUDE)
%.o: %.c $(DEPS) ##prereqs (right of targ) must be up to date (account for changes to .h)
	 $(CC) $(CFLAGS) -c -o $@ $< ##$@ is target, $< is 1st DEP, -c just makes .o (& not executable)
clean:
	rm -f *.o
	cd $(LIBS) && $(MAKE) clean ## $(MAKE) macro expands to prog. running my Makefile & propogates command line flags
fclean: clean
	 rm -f $(NAME)
	 cd $(LIBS) && $(MAKE) fclean
re: fclean all
.PHONY: all clean fclean re ##don't generate files, avoid confusion w/ existing
