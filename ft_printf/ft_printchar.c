/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:48:42 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/20 10:48:17 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}
/*
//return value of succesful write = # of chars written
int	main(void)
{
	char	c;
	int	result;

	c = 'c';
	result = ft_printchar(c);
	write(1, "\n", 1);
	printf("return value: %i\n", result);
}*/
