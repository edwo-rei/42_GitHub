/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:44:45 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/09 20:01:43 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = (ft_strlen(src));
	if (size > 0)
	{
		while ((src[i]) && (size > 1))
		{
			dst[i] = src[i];
			i++;
			size--;
		}
		dst[i] = '\0';
	}
	return (j);
}
