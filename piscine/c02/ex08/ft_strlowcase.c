/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:20:37 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/01 13:25:05 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
*/
char	*ft_strlowcase(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
	return (str);
}
/*
int	main(void)
{
	char 	letters[] = "PISCINE";
	char 	numbers[] = "0123456789";
	char 	mix[] = "PiscIne42";
	char	empty[] = "";

	ft_strlowcase(letters);
	printf("%s\n", letters);
	ft_strlowcase(numbers);
	printf("%s\n", numbers);
	ft_strlowcase(mix);
	printf("%s\n", mix);
	ft_strlowcase(empty);
	printf("%s\n", empty);
}*/
