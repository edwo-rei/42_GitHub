/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:34:45 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/24 13:29:50 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
/*
int	main(int argc, char **argv)
{
	int	i;

	i = 1;//counter variable for args
	if (argc > 1)//must have at least one arg
	{
		while (i < argc)//loop runs through last arg
		{
			printf("%lu\n", strlen(argv[i]));
			printf("%lu\n", ft_strlen(argv[i]));
			i++;//move to next arg
		}
	}
	return (0);
}*/
