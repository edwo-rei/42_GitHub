/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:28:03 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/02 17:24:44 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main(void)
{
	char	src[] = "piscine";
	char	dest[20];

	ft_strcpy(dest, src);
	printf("%s", dest);
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
