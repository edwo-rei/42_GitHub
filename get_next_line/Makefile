# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 12:16:40 by edwo-rei          #+#    #+#              #
#    Updated: 2025/05/28 14:01:15 by edwo-rei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc ##obligatory compiler (cc is set to clang on these machines)
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=n ##Wall & Wextra enable useful warnings (Wextra is stricter, can cause false pos). Werror treats them as errors & compilation fails. -D specifies buffer size for get_next_line function
NAME = get_next_line.a ##designates name of output file, obligatory
DEPS = get_next_line.h ##so if a change is made, .c files will recompile(see below)
SRC = get_next_line.c get_next_line_utils.c
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
