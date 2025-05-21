/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:02:32 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/21 14:01:21 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*may need to change int to long long for ptr. Divide by 16 b/c there are 16 
  chars in hex. Count each recursion before entry b/c count not preserved once 
  a recursion is done*/
int	ft_printhex(unsigned int n, char c)
{
	char	*base;
	int		count;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_printhex(n / 16, c);
	count += write(1, &base[n % 16], 1);
	return (count);
}
/*
int	main(void)
{
	unsigned int	n;
	char		format;
	int		result;

	n = 123456789;
	format = 'X';
	result = ft_printhex(n, format);
	write(1, "\n", 1);
	printf("return value: %i\n", result);
	if (format == 'x')
		result = printf("%x\n", n);
	else
		result = printf("%X\n", n);
	printf("printf return value: %i\n", result);
}*/
