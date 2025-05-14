/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:56:23 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/25 18:28:22 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("%i\n", isascii(argv[1][0]));
		printf("%i\n", ft_isascii(argv[1][0]));
		printf("%i\n", isascii('\0'));
		printf("%i\n", ft_isascii('\0'));
	}
}*/
