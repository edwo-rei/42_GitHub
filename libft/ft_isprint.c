/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:12:14 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/25 18:35:23 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("%i\n", isprint(argv[1][0]));
		printf("%i\n", ft_isprint(argv[1][0]));
	}
}*/
