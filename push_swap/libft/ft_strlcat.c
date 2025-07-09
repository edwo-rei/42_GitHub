/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:52:07 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/09 20:01:26 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	k;

	i = 0;
	j = ft_strlen(dst);
	k = (ft_strlen(dst) + ft_strlen(src));
	if (size > j)
	{
		while (src[i] && (size - j > 1))
		{
			dst[i + j] = src[i];
			i++;
			size--;
		}
		dst[i + j] = '\0';
		return (k);
	}
	else
		return (size + ft_strlen(src));
}
