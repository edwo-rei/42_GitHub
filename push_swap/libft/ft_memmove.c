/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:36:44 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/09 19:57:37 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	if (dst == (void *)0 && src == (void *)0)
		return (NULL);
	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	if (dst <= src)
	{
		while (n-- > 0)
		{
			*pdst = *psrc;
			pdst++;
			psrc++;
		}
	}
	else if (dst > src)
	{
		while (n-- > 0)
			pdst[n] = psrc[n];
	}
	return (dst);
}
