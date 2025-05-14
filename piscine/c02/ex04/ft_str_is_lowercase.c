/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:49:36 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/31 18:59:49 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
*/
int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (!(*str >= 'a' && *str <= 'z'))
			return (0);
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char 	letters[] = "piscine";
	char 	mix_numbers[] = "01234s6789";
	char 	upper_lower[] = "Piscine";
	char	empty[] = "";

	printf("return value is %d\n", ft_str_is_lowercase(letters));
	printf("return value is %d\n", ft_str_is_lowercase(mix_numbers));
	printf("return value is %d\n", ft_str_is_lowercase(upper_lower));
        printf("return value is %d\n", ft_str_is_lowercase(empty));
}*/
