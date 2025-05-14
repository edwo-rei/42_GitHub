# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 19:24:26 by edwo-rei          #+#    #+#              #
#    Updated: 2025/05/14 11:56:19 by edwo-rei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc ##obligatory compiler (cc is set to clang on these machines)
CFLAGS = -Wall -Wextra -Werror ##obligatory flags
NAME = libft.a ##designates name of output archive file, obligatory
DEPS = libft.h ##so if a change is made, .c files will recompile
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
      ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
      ft_strlcat.c ft_strncmp.c ft_toupper.c ft_tolower.c ft_strchr.c \
      ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
      ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
      ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c
OBJ = $(SRC:.c=.o) 

all: $(NAME) ##1st targ defined invoked when typing just "make"
$(NAME): $(OBJ)
	 ar -crs $@ $^ ##creates archive file, c: create, r: add w/ replace, s: create index
%.o: %.c $(DEPS) ##files to right of targ must be up to date (i.e. changes to .h)
	 $(CC) $(CFLAGS) -c -o $@ $< ##$@ is targe, $< is 1st DEP, -c just make .o
clean:
	rm -f *.o
fclean: clean
	 rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re ##don't generate files, avoid confusion w/ existing
