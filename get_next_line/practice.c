#include "get_next_line.h"

int	print_chars(int fd)
{
	//declare & init static int chars_printed. Static so it will maintain
	//count of chars printed after func concludes
	static int 	chars_printed;
	//If you want to initialize it, it must be intialized to 0 on same 
	//line, else it will reset to 0 every time function is called. If not
	//explicitly initialized, will default to 0.
	int	chars_read;//declare int var "chars_read"
	char	buf[BUFFER_SIZE + 1];//declare array of chars "buf", size for 512 chars

	/*call read func, w/ parameters of the fd given in main (for text.txt)
	  & buf array declared above to hold output; will read 50 bytes.
	  Assign its return val to chars_read*/
	chars_read = read(fd, buf, BUFFER_SIZE);
	buf[chars_read] = '\0';//append null char to str created
	printf("%s\n", buf);//print what was read (stored in buf)
	chars_printed += chars_read;//add # chars read to chars_printed
	return (chars_printed);//return current val of chars_printed
}

int main(void)
{
	int	fd;//declare variable of type int called "fd"
	int	chars_printed;//declare int variable "chars_printed"

	chars_printed = 0;//init chars_printed at 0
	fd = open("text.txt", O_RDONLY);//init fd w/ fd of text.txt
	//loop runs as long as < 466 chars have been printed
	while (chars_printed < 466)
	{
		//assign return val of func print_chars to chars_printed
		chars_printed = print_chars(fd);
		//print current val of chars_printed
		printf("chars_printed: %i\n", chars_printed);
	}
	close(fd);
}	
