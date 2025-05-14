/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:28:03 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/02 12:49:36 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	while (*src)//the same as while (src[i] != '\0') with a counter variable
	{
		*dest = *src;//defines current pos in dest as current pos in source
		src++;//moves to next place in source array (or really, in memory dedicated to this "string")
		dest++;//moves to next place in destination array
	}
	*dest = '\0';//appends null charcter at end of string
	return (dest);//returns the values held in dest BUT dest++ has moved us several places forward from the address first given by the pointer. So what is returned won't be the whole string from the beginning, which is why I think I failed the moulinette
}

int main(void)
{
	char	src[] = "piscine";
	char	dest[20];

	printf("%s\n", ft_strcpy(dest, src));//nothing is printed here because the return of ft_strcpy is nothing since the function advanced beyond the positions with characters
	printf("%s", dest);//when I print dest here, it does print the string full of values from src
	return (0);
}
