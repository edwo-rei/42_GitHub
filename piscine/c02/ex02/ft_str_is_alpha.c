/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:58:24 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/02 12:54:55 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
*/
int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
			return (0);//if value in current pos is not a letter, return 0
		str++;//move to next pos
	}
	return (1);//otherwise return 1
}
/*
int	main(void)
{
	char 	letters[] = "piscine";
	char 	numbers[] = "0123456789";
	char 	mix[] = "p15c1n9";
	char	empty[] = "";//to confirm that empty returns 1

	printf("return value is %d\n", ft_str_is_alpha(letters));
	printf("return value is %d\n", ft_str_is_alpha(numbers));
	printf("return value is %d\n", ft_str_is_alpha(mix));
        printf("return value is %d\n", ft_str_is_alpha(empty));
}*/
