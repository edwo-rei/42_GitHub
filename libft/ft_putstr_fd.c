/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:13:58 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/13 13:11:46 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//not necessary to add 1 for null char when using the write function
void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
}
/*
int	main(void)
{
	char	s[] = "lorem ipsum dolor sit amet";
	int	fd;

	fd = open("test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0640);
	if (fd == -1)
		return (1);
	printf("fd: %i\n", fd);
	ft_putstr_fd(s, fd);
	close(fd);
	return (0);
}*/
