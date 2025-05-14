/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:14:44 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/24 17:52:50 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')
		|| ('0' <= c && c <= '9'))
		return (c);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("%i\n", isalnum(argv[1][0]));
		printf("%i\n", ft_isalnum(argv[1][0]));
	}
}*/
