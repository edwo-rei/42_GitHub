/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:27:25 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/01 13:17:50 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
*/
char	*ft_strupcase(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
	return (str);//won't return desired uppercase string b/c has advanced from orig *str ptr beyond positions that contain letters
}
/*
int	main(void)
{
	char 	letters[] = "piscine";
	char 	numbers[] = "0123456789";
	char 	mix[] = "PiscIne42";
	char	empty[] = "";

	ft_strupcase(letters);//test didn't show problem b/c not printing return value of function
	printf("%s\n", letters);
	ft_strupcase(numbers);
	printf("%s\n", numbers);
	ft_strupcase(mix);
	printf("%s\n", mix);
	ft_strupcase(empty);
	printf("%s\n", empty);
}*/
