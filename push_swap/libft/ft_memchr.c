/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:09:22 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/09 19:56:09 by edwo-rei         ###   ########.fr       */
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
