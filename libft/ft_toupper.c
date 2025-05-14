/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:13:27 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/01 13:30:48 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= 32;
	return (c);
}
/*
int	main(void)
{
	printf("%c\n", ft_toupper('c'));
	printf("%c\n", ft_toupper('A'));
	printf("%c\n", ft_toupper(99));
	printf("%c\n", ft_toupper('0'));
	printf("%c\n", ft_toupper('!'));
	printf("%c\n", ft_toupper(32));
}*/
