/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:15:21 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/20 11:32:48 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	i;

	i  = 0;
	while (str[i])
	{
		ft_printchar(str[i]);
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char	str[] = "Test string";
	int	result;

	result = ft_printstr(str);
	write(1, "\n", 1);
	printf("return value: %i\n", result);
	result = printf("%s\n", str);
	printf("printf return value: %i\n", result);
}*/
