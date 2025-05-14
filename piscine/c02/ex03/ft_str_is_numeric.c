/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:27:30 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/31 18:46:41 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
*/
int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char 	letters[] = "piscine";
	char 	numbers[] = "0123456789";
	char 	mix[] = "p15c1n9";
	char	empty[] = "";

	printf("return value is %d\n", ft_str_is_numeric(letters));
	printf("return value is %d\n", ft_str_is_numeric(numbers));
	printf("return value is %d\n", ft_str_is_numeric(mix));
        printf("return value is %d\n", ft_str_is_numeric(empty));
}*/
