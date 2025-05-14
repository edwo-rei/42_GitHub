/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:36:44 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/01 13:01:47 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//assures that info in src won't be overwritten when copied to dst
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	if (dst == (void *)0 && src == (void *)0)
		return (NULL);
	pdst = (unsigned char *)dst;//must cast void ptr to unsigned char ptrs
	psrc = (unsigned char *)src;//to manipulate them
	if (dst <= src)//refers to the location in memory
	{
		while (n-- > 0)
		{
			*pdst = *psrc;
			pdst++;
			psrc++;
		}
	}
	else if (dst > src)//in this case there is a risk of overwriting info from src and causing data loss, so we copy starting w/ last char
	{
		while (n-- > 0)//order of precedence checks condition before 
			pdst[n] = psrc[n];//decreasing n, but decreases n before assigning psrc[n] to pdst[n]
	}
	return (dst);
}
/*
int	main(void)
{
	char	dst[] = "Lorem ipsum dolor sit a";
	char	src[] = "consectetur";
	char	blank[] = "aaaa";
	char	cushion[] = "bbbb";
	char	dest[] = "Lorem ipsum dolor sit a";
	char	source[] = "consectetur";
	size_t	n;

	n = 5 * sizeof(char);
	printf("dst ptr is: %p\n", dst);
	printf("src ptr is: %p\n", src);
	printf("dest ptr is: %p\n", dest);
	printf("source ptr is: %p\n", source);
	memmove(dst, src, n);
	printf("memmove returns: %s\n", dst);
	ft_memmove(dest, source, n);
	printf("ft_memmove returns: %s\n", dest);
	return (0);
}*/
