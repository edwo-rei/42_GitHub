/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:56:08 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/02 12:53:28 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	while (*src && n)//while there are characters in source array & while n(spaces that can be used in dest) is not 0
	{
		*dest = *src;
		src++;
		dest++;
		n--;//decrease spaces available in dest by 1
	}
	while (n > 0)//fill remaining empty spaces with null characters
	{
		*dest = '\0';
		dest++;
		n--;//after each null character has been added, space available decreases by 1
	}
	return (dest);//function will not return chars in string dest b/c has advanced beyond their pos
}

int main(void)
{
	char	src[13] = "foobarfoobar";
	char	dest[20];

	ft_strncpy(dest, src, 20);
	printf("%s\n", dest);//shows transformed dest, but not its return value
	printf("%c\n", dest[6]);//attempting to confirm that null characters are
	printf("%c\n", dest[7]);//added by printing a new line after each
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
