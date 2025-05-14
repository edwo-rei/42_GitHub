/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:09:22 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/02 12:49:19 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	letter;

	str = (unsigned char *)s;
	letter = (unsigned char)c;
	while (n > 0)
	{
		if (*str == letter)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s[] = "Like looking for a needle in a haystack";
	int	c;
	size_t	n;

	c = 'e';
	n = sizeof(s);
	printf("%p\n", memchr(s, c, n));
	printf("%c\n", *(unsigned char *)(memchr(s, c, n)));
	printf("%p\n", ft_memchr(s, c, n));
	printf("%c\n", *(unsigned char *)(ft_memchr(s, c, n)));
	c = 'y';
	printf("%p\n", memchr(s, c, n));
	printf("%c\n", *(unsigned char *)(memchr(s, c, n)));//comment if absent
	printf("%p\n", ft_memchr(s, c, n));
	printf("%c\n", *(unsigned char *)(ft_memchr(s, c, n)));//comm if absent
	return (0);
}*/
