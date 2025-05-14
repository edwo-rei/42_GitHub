/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:58:29 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/03 16:25:27 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	one;
	int	two;

	i = 0;
	one = 0;
	two = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] > s2[i])
			one += (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			two += (s2[i] - s1[i]);
		i++;
	}
	return (one - two);
}

int	main(void)
{
	char	s1[] = "abc";
	char	s2[] = "abc";
	char	s3[] = "abd";
	char	s4[] = "adz";

	printf("%i\n", strcmp(s1, s2));
	printf("%i\n", strcmp(s1, s3));
	printf("%i\n", strcmp(s1, s4));
	printf("%i\n", strcmp(s3, s1));
	printf("%i\n", ft_strcmp(s1, s2));
	printf("%i\n", ft_strcmp(s1, s3));
	printf("%i\n", ft_strcmp(s1, s4));
	printf("%i\n", ft_strcmp(s3, s1));

	return (0);
}
