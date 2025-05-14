/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:14:03 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/02 14:04:58 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n > 0)//must continue even after null char at end of string
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "\xff\0\0\xaa\0\xde\xffMACOSX\xff";
	char	s2[] = "\xff\0\0\xaa\0\xde\x00MBS";
	char	s3[] = "abb";
	char	s4[] = "ab";
	char	s5[] = "\201";
	size_t	n;

	n = 9;
	printf("memcmp returns %i\n", memcmp(s1, s2, n));
	printf("ft_memcmp returns %i\n", ft_memcmp(s1, s2, n));
	printf("memcmp returns %i\n", memcmp(s1, s3, n));
	printf("ft_memcmp returns %i\n", ft_memcmp(s1, s3, n));
	printf("memcmp returns %i\n", memcmp(s1, s4, n));
	printf("ft_memcmp returns %i\n", ft_memcmp(s1, s4, n));
	printf("memcmp returns %i\n", memcmp(s1, s5, n));
	printf("ft_memcmp returns %i\n", ft_memcmp(s1, s5, n));
}*/
