/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:21:36 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/24 17:55:12 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (c);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("%i\n", isdigit(argv[1][0]));
		printf("%i\n", ft_isdigit(argv[1][0]));
	}
}*/
