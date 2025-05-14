CC = cc #use cc to compile
CFLAGS = -Wall -Wextra -Werror
NAME = hellomake.a #defined as .a file to be an archive, removing .a will render an executable file
DEPS = hellomake.h
OBJ = hellomake.o hellofunc.o

all: $(NAME) #create an all target that makes sure all other targets are run
$(NAME): $(OBJ) # compile $(NAME) target w/ obj files as prereqs, so they'll created
	ar -crs $@ $^ 

%.o: %.c $(DEPS) #will update .c files and dependencies (.h files) before compiling object files
	$(CC) $(CFLAGS) -c -o $@ $< #only need .c files to compile, if we included all prereqs it would try to creat multiple .o files w/ same name

clean:
	rm -f *.o #removes all object files created

fclean: clean #delete all files generated not in orig source 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
