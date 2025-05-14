/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:22:37 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/25 12:31:36 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <bsd/string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	l;

	i = 0;
	l = 0;
	while (dest[i] && size)
	{
		k = ++i;
		size--;
	}
	while (src[l])
		l++;
	if (size > 0)
	{
		while (*src && (size - 1 > 0))
		{
			dest[i] = *src;
			i++;
			src++;
			size--;
		}
		dest[i] = '\0';
	}
	return (k + l);
}

int	main(void)
{
	char	dest[] = "Hello ";
	char	src[] = "world";
	char	destination[] = "Hello ";
	char	source[] = "world";

	printf("Return value of ft_strlcat: %u\n", ft_strlcat(dest, src, 0));
	printf("New dest: %s\n", dest);
	printf("Return value of strlcat: %lu\n", strlcat(destination, source, 0));
	printf("New destination: %s\n", destination);
	return (0);
}
