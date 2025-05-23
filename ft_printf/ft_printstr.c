/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:15:21 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/21 20:22:28 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//added protection against NULL str ptr, will output "(null)" to warn user
//just like established printf() function
int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char	*str;
	int	result;

	str = NULL;
	result = ft_printstr(str);
	write(1, "\n", 1);
	printf("return value: %i\n", result);
	result = printf("%s\n", str);
	printf("printf return value: %i\n", result);
}*/
