/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orig.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:27:22 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/01 17:27:14 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	if ('a' <= *str && *str <= 'z')
		*str -= 32;
	str++;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
	return (str);
}

int	main(void)
{
	char 	letters[] = "piscine";
	char 	numbers[] = "42 is the place";
	char 	mix[] = "PiscIne42";
	char	empty[] = "";

	ft_strcapitalize(letters);
	printf("%s\n", letters);
	ft_strcapitalize(numbers);
	printf("%s\n", numbers);
	ft_strcapitalize(mix);
	printf("%s\n", mix);
	ft_strcapitalize(empty);
	printf("%s\n", empty);
}
