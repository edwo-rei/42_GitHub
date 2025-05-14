/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:15:10 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/09 12:37:03 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	//return NULL if there is nothing in s
	if (s == 0)
		return (0);
	//if start is beyond s, return a valid empty string (""), but not NULL, which typically signals an allocation failure
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	//if len exceeds last char in s, cut len down to max possible to avoid undefined behavior after NULL char is reached
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	//initializes pointer to sub by allocating memory for it
	sub = malloc(len + 1);
	if (sub == 0)
		return (0);//signals failure to allocate memory
	i = 0;
	//assign chars indicated by start & len to sub
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	//append NULL char to end of substring
	sub[i] = 0;
	return (sub);
}
/*
int	main(void)
{
	char		str[] = "Test string";
	char		*substring;
	unsigned int	start;
	size_t		length;

	start = 28;
	length = 25;
	substring = ft_substr(str, start, length);
	printf("substring: %s\n", substring);
	free(substring);
}*/
