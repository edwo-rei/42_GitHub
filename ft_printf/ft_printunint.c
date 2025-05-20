/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:29:58 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/20 13:39:54 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunint(unsigned int n)
{
	char	reverse[11];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
		count += write(1, "0", 1);
	while (n != 0)
	{
		reverse[i++] = (n % 10) + 48;
		n /= 10;
	}
	while (i > 0)
		count += write(1, &reverse[--i], 1);
	return (count);
}
/*
int	main(void)
{
	unsigned int	n;
	int	result;

	n = 4294967295;
	result = ft_printunint(n);
	write(1, "\n", 1);
	printf("return value: %i\n", result);
	result = printf("%u\n", n);
	printf("printf return value: %i\n", result);
}*/
