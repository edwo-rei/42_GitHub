/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:11:42 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/09 19:59:40 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ch;
	char	letter;

	ch = (char *)s;
	letter = (char)c;
	while (*ch)
	{
		if (*ch == letter)
			return (ch);
		ch++;
	}
	if (*ch == letter)
		return (ch);
	return (NULL);
}
