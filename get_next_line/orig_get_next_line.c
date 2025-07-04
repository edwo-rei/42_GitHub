/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:19:23 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/03 18:01:18 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*This function fills the buffer with the chars read by the read function. If an
  \n is found in the buffer, it breaks the loop & returns a ptr to the resulting
  string. The read function uses a ptr to track what has been read so far for the   correspondingfile descriptor.*/
static char	*fill_line(int fd, char *buffer, char *chars_read)
{
	char	*tmp;
	int	n_read;

	//can't use strjoin if chars_read empty, so initialize if empty
	//need to use ft_strdup here for free(tmp) below to work
	if (!chars_read)
		chars_read = ft_strdup("");
	n_read = 1;
	//n_read will equal 0 when no chars are read b/c nothing left to read. 
	//A read error will return -1
	while (n_read > 0)
	{
		//read buf size into buf & assign return value to n_read
		//***what if I just read 1 char at a time & checked if it was \n?
		n_read = read(fd, buffer, BUFFER_SIZE);
		//must protect against read failing. If it returns -1, free chars_read
		//& return NULL to get_next_line. This caused 1st failure
		if (n_read < 0)
		{
			free(chars_read);
			return (NULL);
		}
		//if nothing is read, we can break out of the loop
		if (n_read == 0)
			break ;
		//append null char
		buffer[n_read] = '\0';
		//assign tmp ptr to what chars_read is currently pointing at
		tmp = chars_read;
		//join what chars_read was pointing to before to what was read 
		//into buf - mem is dynamically allocated for return str,
		//now pointed to by chars_read
		chars_read = ft_strjoin(tmp, buffer);
		//now we can free up what chars_read was pointing to before,
		//which is still pointed to by tmp
		free(tmp);
		//if a \n was encountered in last read, break out of loop
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (chars_read);
}

/*This function takes the line w/ a \n in it, inserts a \0 after the \n &
  returns a ptr to a string w/ the chars after the \n*/
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
	//ft_substr. If no chars are left after \n, ft_substr calls ft_strdup("")
	//& also dynamically allocates mem for the null char
	left_over = ft_substr(line, i + 1, ft_strlen(line) - i);
	//check to see if only a null char was left to be read, if so, 
	//return NULL
	if (*left_over == '\0')
	{
		//since ft_substr used dynamic memory allocation (ft_strdup("")), 
		//that mem must be freed
		free(left_over);
		return (NULL);
	}
	//set line[i + 1] to \0 so that it will only be displayed until there
	line[i + 1] = '\0';
	//return left over chars
	return (left_over);
}

/*This function checks for errors, invalid input or a failure to allocate,
  then calls fill_line to read the text file indicated by fd until a new
  line is encountered. It calls clean_line to insert a \0 after the \n &
  return a ptr to the remaining This is a short text.chars. This function then returns a ptr to 
  the line read, including the terminating \n. If fill_line returns NULL, 
  it returns NULL*/
char	*get_next_line(int fd)
{
	/*BUFFER_SIZE will define buffer size for read function. It will be
	  set by evaluators at compilation. The program must compile w/o the 
	  -D BUFFER_SIZE=n flag as well*/
	char		*buffer;
	char		*line;
	/*static var will hold chars read but not yet returned as part of 
	 a line. Auto-initialized to NULL for ptr if not initialized explicitly*/
	static char	*chars_read;

	//allocate memory in heap according to buf size given at compilation & 
	//assign its address to buffer
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	/*protect against invalid fd, buffer size that can't work, that file
	  exists & is accessible (failed read will return -1 - w/ 0, 0 will 
	  return 0 chars read) & failed malloc*/
	if (fd < 0 || BUFFER_SIZE < 1 || !buffer)
	{
		//free buffer & chars read to avoid leaks in case of failed read
		//(and pass w/ Paco)
		free(buffer);
		free(chars_read);
		//set ptrs to NULL to avoid ptrs that point to invalid memory &
		//nullify problems caused by a double free
		buffer = NULL;
		chars_read = NULL;
		return (NULL);
	}
	/*read the input indicated by the fd until a \n is found, join the 
	  strings read each time read was called together into a single string
	  & return the resulting string*/
	line = fill_line(fd, buffer, chars_read);
	//free up buffer, now that what is in buffer is also in chars_read
	free(buffer);
	//remove chars after \n & assign them to chars_read
	chars_read = clean_line(line);
	//check to see if clean_line has set line to point to a null char, if so 
	//return NULL
	if (!*line)
	{
		//free line b/c one byte will still be used for null char
		free(line);
		return (NULL);
	}
	//return the chars read up to & including the \n
	return (line);
}

/*The main function opens a text file and passes its file descriptor to the
  get_next_line function. It also declares a char ptr variable that points
  to the return value of get_next_line, and the then prints the chars stored
  there. The function is called in a loop until the entire text file has been
  read.*/
int main(void)
{
	int		fd;//declare variable of type int called "fd"
	char	*line_read;//declare char ptr variable "line_read"
	//Doesn't need to be initialized b/c just a ptr to return val of 
	//get_next_line, which eventually returns a ptr to static var chars_read 

	fd = 42;//open("text.txt", O_RDONLY);//init fd w/ fd of text.txt. txt  
	//files automatically end w/ \n, according to ChatGPT(?). You can set
	//to STDIN by making fd = 0, then on the command line using: 
	//printf OR echo -e "<string>" | <program name, e.g. ./a.out>
	//OR ./a.out < <file_name>
	//double parentheses around while condition advises the compiler that I'm 
	//doing this on purpose and surpresses the warning about assignment inside
	//a condition. Assignation inside condition is more concise, but you could
	//also assign before the loop & then again at the end of the loop.
	while ((line_read = get_next_line(fd)))
	{
		//print line read, no \n needed b/c lines will finish w/ \n
		printf("%s", line_read);
		//free memory allocated to line just printed
		free(line_read);
	}
	close(fd);
}
