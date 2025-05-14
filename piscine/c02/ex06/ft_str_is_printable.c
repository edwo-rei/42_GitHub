/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:13:21 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/02 12:55:45 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
*/
int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (!((*str >= 33 && *str <= 126)))//range of printable chars in ascii
			return (0);
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char 	letters[] = "Piscine";
	char 	numbers[] = "42IsTheAnswer!";
	char 	mix[] = "aBc7!\07@";
	char	empty[] = "";

	printf("return value is %d\n", ft_str_is_printable(letters));
	printf("return value is %d\n", ft_str_is_printable(numbers));
	printf("return value is %d\n", ft_str_is_printable(mix));
        printf("return value is %d\n", ft_str_is_printable(empty));
}*/
