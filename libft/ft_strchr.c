/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:11:42 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/01 18:46:28 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ch;
	char	letter;

	ch = (char *)s;
	letter = (char)c;//allows values beyond 127 to be used, only lower byte matters, like strchr
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
/*
int	main(void)
{
	char	s[] = "Like looking for a needle in a haystack";
	int	c;

	c = 't' + 256;
	printf("%p\n", strchr(s, c));
	printf("%c\n", *(strchr(s, c)));
	printf("%p\n", ft_strchr(s, c));
	printf("%c\n", *(ft_strchr(s, c)));
	c = '\0';
	printf("%p\n", strchr(s, c));
	printf("%c\n", *(strchr(s, c)));
	printf("%p\n", ft_strchr(s, c));
	printf("%c\n", *(ft_strchr(s, c)));
	return (0);
}*/
