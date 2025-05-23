/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:02:32 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/21 19:02:15 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//char parameter is lower or uppercase x; used by if statement to set a base w/
//corresponding lower or uppercase letters
int	ft_printhex(unsigned int n, char c)
{
	char	*base;
	int		count;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = 0;
	//recursive calls divide n by base count until n is a single digit. This
	//digit, taken as a remainder & used as an index to write from the base, 
	//gives the char in the largest (leftmost) place. Exiting the last recursion 
	//& taking another remainder gets the next place, and so on, until remainder 
	//is taken from original (full) number & whole number has been written. 
	//Debug a base 10 function if you need a visual reminder
	if (n >= 16)
		count += ft_printhex(n / 16, c);
		//Divide by 16 b/c there are 16 chars in hex
		//"count +=" takes into account count from deepest level of recursion 
		//each time a level resolves and gives count as return value
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
