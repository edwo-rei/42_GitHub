/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:02:28 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/01 17:06:39 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += 32;
	return (c);
}
/*
int	main(void)
{
	printf("%c\n", ft_tolower('C'));
	printf("%c\n", ft_tolower('a'));
	printf("%c\n", ft_tolower(68));
	printf("%c\n", ft_tolower('0'));
	printf("%c\n", ft_tolower('!'));
	printf("%c\n", ft_tolower(32));
}*/
