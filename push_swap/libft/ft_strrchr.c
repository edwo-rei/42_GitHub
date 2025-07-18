/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:18:32 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/09 20:03:34 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			letter;
	char			*str;
	unsigned long	i;

	letter = (char)c;
	str = (char *)s;
	i = ft_strlen(s);
	while (i-- > 0)
	{
		if (str[i] == letter)
			return (str + i);
	}
	if (str[ft_strlen(s)] == letter)
		return (str + ft_strlen(s));
	return (NULL);
}
