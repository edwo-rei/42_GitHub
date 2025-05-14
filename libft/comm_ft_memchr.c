/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:09:22 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/02 12:48:49 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	letter;

	str = (unsigned char *)s;//cast void ptr s to a ptr to unsigned char
	letter = (unsigned char)c;//cast int c to an unsigned char
	while (n > 0)//loop through str checking for char
	{
		if (*str == letter)//if found, return ptr to that mem address
			return (str);
		str++;
		n--;
	}
	return (NULL);//if not found, return NULL
}
/*
int	main(void)
{
	char	s[] = "Like looking for a needle in a haystack";
	int	c;
	size_t	n;

	c = 'y';
	n = sizeof(s);
	printf("size of s is %lu\n", n);
	printf("%p\n", memchr(s, c, n));
	printf("%c\n", *(unsigned char *)(memchr(s, c, n)));//must deref & cast
	printf("%p\n", ft_memchr(s, c, n));
	printf("%c\n", *(unsigned char *)(ft_memchr(s, c, n)));
	c = 'z';
	printf("%p\n", memchr(s, c, n));
	printf("%s\n", *(unsigned char *)(memchr(s, c, n)));//must comment if absent
	printf("%p\n", ft_memchr(s, c, n));
	printf("%s\n", *(unsigned char *)(ft_memchr(s, c, n)));
	return (0);
}*/
