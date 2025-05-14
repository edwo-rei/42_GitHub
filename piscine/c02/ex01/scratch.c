/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:56:08 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/27 20:53:14 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	while ((src && *src) && n)//the same as (*src != '\0' && n != 0)
	{
		*dest = *src;
		src++;
		dest++;
		n--;
	}
	while (n > 0)
	{
		*dest = '\0';
		printf("%d\n", n);
		dest++;
		n--;
	}
	return (dest);
}

int main(void)
{
	char	src[13] = "foobarfoobar";
	char	dest[20];

	ft_strncpy(dest, src, 20);
	printf("%s\n", dest);
	printf("%c\n", dest[6]);
	printf("%c\n", dest[7]);
	printf("%c\n", dest[8]);
	printf("%c\n", dest[9]);
	printf("%c\n", dest[10]);
	printf("%c\n", dest[11]);
	printf("%c\n", dest[12]);
	printf("%c\n", dest[13]);
	printf("%c\n", dest[14]);
	printf("%c\n", dest[15]);
	printf("%c\n", dest[16]);
	printf("%c\n", dest[17]);
	printf("%c\n", dest[18]);
	printf("%c\n", dest[19]);
	return (0);
}
