/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:43:51 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/13 11:56:41 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*The open command opens (or creates) the file designated by pathname. The
  O_WRONLY flag opens file in write-only access mode. O_TRUNC says that if file 
  already exists and access mode allows writing, its content  will be truncated 
  to length 0. O_CREAT allows nonexistent file to be created. "0640" for mode 
  means that owner has read & write permission & group has read permission. 
  The fd output is an int used as a reference to that open file, allowing it to
  be written to using that reference. 
  The fd output is an int used as a reference to that open file, allowing it to
  be written to using that reference. The close command closes that file 
  descriptor so it can be reused
int	main(void)
{
	char	c;
	int	fd;

	c = 'z';
	fd = open("test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0640);
	if (fd == -1)
		return (1);
	printf("fd: %i\n", fd);
	ft_putchar_fd(c, fd);
	close(fd);
	return (0);
}*/
