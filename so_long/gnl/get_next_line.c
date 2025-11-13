/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:19:23 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/03 19:34:24 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*This function fill the buffer with the chars read by the read function. When a
  \n is found in the buffer, it returns a ptr to the resulting string. The read
 function uses a ptr to track what has been read so far for the corresponding 
 file descriptor.*/
static char	*fill_line(int fd, char *buffer, char *chars_read)
{
	char	*tmp;
	int		n_read;

	if (!chars_read)
		chars_read = my_strdup("");
	n_read = 1;
	while (n_read > 0)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read < 0 || !chars_read)
		{
			free(chars_read);
			return (NULL);
		}
		if (n_read == 0)
			break ;
		buffer[n_read] = '\0';
		tmp = chars_read;
		chars_read = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (chars_read);
}

/*This function takes the line w/ a \n in it, inserts a \0 after the \n & 
  returns a ptr to a string w/ the chars after the \n*/
static char	*clean_line(char *line)
{
	char	*left_over;
	int		i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	left_over = ft_substr(line, i + 1, my_strlen(line) - i);
	if (*left_over == '\0')
	{
		free(left_over);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (left_over);
}

/*This function checks for errors, invalid input or a failure to allocate,
  then calls fill_line to read the text file indicated by fd until a new
  line is encountered. It calls clean_line to insert a \0 after the \n &
  return a ptr to the remaining chars. This function then returns a ptr to
  the line read, including the terminating \n. If fill_line returns NULL,
  it returns NULL*/
char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*chars_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE < 1 || !buffer)
	{
		free(buffer);
		free(chars_read);
		buffer = NULL;
		chars_read = NULL;
		return (NULL);
	}
	line = fill_line(fd, buffer, chars_read);
	free(buffer);
	chars_read = clean_line(line);
	if (!line || !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/*The main function opens a text file and passes its file descriptor to the 
  get_next_line function. It also declares a char ptr variable that points 
  to the return value of get_next_line, and the then prints the chars stored
  there. The function is called in a loop until the entire text file has been
  read.
int	main(void)
{
	int		fd;
	char	*line_read;

	fd = open("text.txt", O_RDONLY);
	line_read = get_next_line(fd);
	while (line_read)
	{
		printf("%s", line_read);
		free(line_read);
		line_read = get_next_line(fd);
	}
	close(fd);
}*/
