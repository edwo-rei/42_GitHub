/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:22:37 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/07 14:26:14 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <bsd/string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;//counter for whole function
	unsigned int	j;//counter for appending src
	unsigned int	k;//variable to hold length of original dest
	unsigned int	l;//counter to get length of original src

	i = 0;//set all counters to 0
	j = 0;
	l = 0;
	while (dest[i] && size)//while loop increases i as long as size is > 0
	{
		i++;
		size--;//decreases value of size variable to compensate for dest
	}
	k = i;//hold orig value of dest for return value calc
	while (src[l])//count length of src for return value calc
		l++;
	if (size > 0)//if size isn't still > 0, function will return orig dest and value of size + source. Otherwise, append src
	{
		while (src[j] && (size - 1 > 0))//while there are chars in src and size allows room to append '\0'
		{	
			dest[i] = src[j];//add src char on to dest
			i++;
			j++;
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
	//unsigned int	destsize;

	/*destsize = sizeof(dest) + sizeof(src) - 1;
	printf("Size of buffer: %u\n", destsize);
	printf("Return value of ft_strlcat: %u\n", ft_strlcat(dest, src, destsize));
	printf("New dest: %s\n", dest);*/

	printf("Return value of truncated ft_strlcat: %u\n", ft_strlcat(dest, src, 0));
	printf("Truncated dest: %s\n", dest);

	/*destsize = sizeof(destination) + sizeof(source) - 1;
	printf("Size of buffer: %u\n", destsize);
	printf("Return value of strlcat: %lu\n", strlcat(destination, source, destsize));
	printf("New destination: %s\n", destination);*/

	printf("Return value of truncated strlcat: %lu\n", strlcat(destination, source, 0));
	printf("Truncated destination: %s\n", destination);
	return (0);
}
