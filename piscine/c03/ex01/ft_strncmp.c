/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:04:17 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/03 17:23:21 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <string.h>
#include <stdio.h>
*/
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && n > 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		n--;
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

	printf("%i\n", strncmp(s1, s2, 4));
	printf("%i\n", strncmp(s1, s3, 2));
	printf("%i\n", strncmp(s1, s4, 4));
	printf("%i\n", strncmp(s3, s1, 4));
	printf("%i\n", strncmp(s1, s5, 4));
	printf("%i\n", ft_strncmp(s1, s2, 4));
	printf("%i\n", ft_strncmp(s1, s3, 2));
	printf("%i\n", ft_strncmp(s1, s4, 4));
	printf("%i\n", ft_strncmp(s3, s1, 4));
	printf("%i\n", ft_strncmp(s1, s5, 4));
	return (0);
}*/
