/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:19:23 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/06/19 13:05:45 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*This function will fill the line to be written with the chars read by the
  read function until a \n is reached, then return a ptr to the resulting 
  string*/
static char	*fill_line(int fd, char *buffer, char *chars_read)
{
	char	*tmp;
	int	n_read;

	//can't use strjoin if chars_read empty, so initialize if empty
	if (!chars_read)
		chars_read = "";//may need ft_strdup here to allocate memory
	n_read = 1;
	//n_read will equal 0 when no chars are read b/c nothing left to read. 
	//A read error will return -1
	while (n_read > 0)
	{
		//read buf size into buf & assign return value to n_read
		//***what if I just read 1 char at a time & checked if it was \n?
		n_read = read(fd, buffer, BUFFER_SIZE);
		//append null char
		buffer[n_read] = '\0';
		//assign what's in chars_read to a temp ptr to be able to join it
		//w/ buf - IS THIS NECESSARY?
		tmp = chars_read;
		//join what chars_read was holding before to what was read 
		//into buf
		chars_read = ft_strjoin(tmp, buffer);
		//if a \n was encountered in last read, break out of loop
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (chars_read);
}

/*This function takes the line w/ a \n in it, cuts off whatever comes after the \n & returns everything after the \n*/
static char	*clean_line(char *line)
{
	char	*left_over;//possible to eliminate this var & use chars_read?
	int	i;

	i = 0;
	//loop through line until \n or \0 is encountered
	while (line[i] && line[i] != '\n')
		i++;
	//if \0 is encountered, return NULL, nothing left for this function to do
	if (line[i] == '\0')
		return (NULL);
	//left_over points to chars after \n, allocated dynamically to mem using
	//ft_substr
	left_over = ft_substr(line, i + 1, ft_strlen(line) - i);
	//check to see if only a null char was left to be read, if so, 
	//return NULL
	if (*left_over == '\0')
	{
		//since ft_substr used dynamic memory allocation, that mem must 
		//be freed
		free(left_over);
		return (NULL);
	}
	//set line[i + 1] to \0 so that it will only be displayed until there
	line[i + 1] = '\0';
	//return left over chars
	return (left_over);
}

/*This function checks for errors or invalid input, then calls fill_line to read the text file indicated by fd until a new line is encountered, then returns the line read, including the terminating \n*/
char	*get_next_line(int fd)
{
	/*BUFFER_SIZE will define buffer size for read function. It will be
	  set by evaluators at compilation. The program must compile w/o the 
	  -D BUFFER_SIZE=n flag as well*/
	char		*buffer;
	char		*line;
	/*static var will hold chars read but not yet returned as part of 
	 a line. Auto-initialized to NULL for ptr if not initialized explicitly.
	 Memory not allocated to stack or heap, but to fixed location in the 
	 data or BSS segment (if initialized or not) of memory. The strings
	 that it will point to are each stored in the read-only data segment, so 
	 they're not dynamically allocated & don't need to be freed, & no leaks 
	 are caused*/
	static char	*chars_read;

	/*protect against invalid fd, buffer size that can't work, & failed read 
	  (which will return -1 - w/ 0, 0 will return 0 chars read)*/
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	//allocate memory in buffer according to buf size given at compilation
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	/*read the input indicated by the fd until a \n is found, join the 
	  strings read each time read was called together into a single string
	  & return the resulting string*/
	line = fill_line(fd, buffer, chars_read);
	//remove chars after \n & assign them to chars_read
	chars_read = clean_line(line);
	//check to see if clean_line has set line to point to a null char, if so 
	//return NULL
	if (!*line)
		return (NULL);
	//return the chars read up to & including the \n
	return (line);
}

/*The main function opens a text file and passes its file descriptor to the get_next_line function. It also declares a char ptr variable that it assigns the output of get_next_line to, and the then prints it. The function is called in a loop until the entire text file has been read.*/
int main(void)
{
	int		fd;//declare variable of type int called "fd"
	char	*line_read;//declare char ptr variable "line_read"
	//Doesn't need to be initialized b/c just a ptr to return val of 
	//get_next_line, which eventually returns a ptr to static var chars_read 

	fd = open("text.txt", O_RDONLY);//init fd w/ fd of text.txt
	//double parentheses around while condition advises the compiler that I'm 
	//doing this on purpose and surpresses the warning about assignment inside
	//a condition
	while ((line_read = get_next_line(fd)))
	{
		//print line read, no \n needed b/c lines will finish w/ \n
		printf("%s", line_read);
	}
	close(fd);
}
