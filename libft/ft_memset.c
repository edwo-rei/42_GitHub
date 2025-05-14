/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:07:09 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/30 13:54:29 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;//since *s is void, it can't be dereferenced directly, we need to to cast it to an unsigned char using a ptr variable to the same mem address
	while (n > 0)
	{
		*ptr = (unsigned char)c;//need to cast int to unsigned char
		ptr++;
		n--;
	}
	return (s);
}
/*
int	main(void)
{
	char	str1[] = "test-string";
	char	str2[] = "test-string";
	int	i;
	size_t	n;

	i = '0';
	n = 8 * sizeof(char);
	memset(str1, i, n);
	printf("memset returns: %s\n", str1);
	ft_memset(str2, i, n);
	printf("ft_memset returns: %s\n", str2);
	return (0);
}*/
