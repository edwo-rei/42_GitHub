/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:57:14 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/02 16:38:38 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	//below: to mimic memcpy, return NULL only if both scr & dst are NULL
	if (dst == (void *)0 && src == (void *)0)//(void *)0 is the safe, unambiguous way to write a null pointer constant
		return (NULL);
	pdst = (unsigned char *)dst;//must cast here to avoid error in compile
	psrc = (unsigned char *)src;//of assigning to unsigned char * from const void *
	while (n > 0)
	{
		*pdst = *psrc;
		pdst++;
		psrc++;
		n--;
	}
	return (dst);
}
/*
int	main(void)
{
	char	dst[] = "test";
	char	src[] = "string";
	char	dest[] = "test";
	char	source[] = "string";
	size_t	n;

	n = 3 * sizeof(char);
	memcpy(dst, src, n);
	printf("memcpy returns: %s\n", dst);
	ft_memcpy(dest, source, n);
	printf("ft_memcpy returns: %s\n", dest);
	return (0);
}*/
