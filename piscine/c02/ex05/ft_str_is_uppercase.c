/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:04:12 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/31 19:08:54 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
*/
int	ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (!(*str >= 'A' && *str <= 'Z'))
			return (0);
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char 	letters[] = "PISCINE";
	char 	mix_numbers[] = "01234S6789";
	char 	upper_lower[] = "Piscine";
	char	empty[] = "";

	printf("return value is %d\n", ft_str_is_uppercase(letters));
	printf("return value is %d\n", ft_str_is_uppercase(mix_numbers));
	printf("return value is %d\n", ft_str_is_uppercase(upper_lower));
        printf("return value is %d\n", ft_str_is_uppercase(empty));
}*/
