/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:15:28 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/29 12:00:53 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0 && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		n--;
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("%i\n", strncmp(argv[1], argv[2], atoi(argv[3])));
		printf("%i\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	}
	printf("%i\n", strncmp("test\200", "test\0", 6));
	printf("%i\n", ft_strncmp("test\200", "test\0", 6));
	return (0);
}*/
