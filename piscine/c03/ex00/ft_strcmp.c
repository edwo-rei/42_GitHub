/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:58:29 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/03 16:52:52 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <string.h>
#include <stdio.h>
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "abc";
	char	s2[] = "abc";
	char	s3[] = "abd";
	char	s4[] = "ABC";
	char	s5[] = "ab";

	printf("%i\n", strcmp(s1, s2));
	printf("%i\n", strcmp(s1, s3));
	printf("%i\n", strcmp(s1, s4));
	printf("%i\n", strcmp(s3, s1));
	printf("%i\n", strcmp(s1, s5));
	printf("%i\n", ft_strcmp(s1, s2));
	printf("%i\n", ft_strcmp(s1, s3));
	printf("%i\n", ft_strcmp(s1, s4));
	printf("%i\n", ft_strcmp(s3, s1));
	printf("%i\n", ft_strcmp(s1, s5));
	return (0);
}*/
