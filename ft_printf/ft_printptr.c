/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:39:50 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/22 20:35:44 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <inttypes.h> - to see how mem address prints w/o %p format specifier

static int	convert_hex(uintptr_t ptr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	//not a problem to declare ptr and fill it with this str b/c it's a str literal
	//w/ a fixed length, memory isn't allocated dynamically based on varying length
	//but if I tried to change the str or return the ptr, it would cause undefined
	//behavior.
	count = 0;
	//recursive calls divide n by base count until n is a single digit. This
	//digit, taken as a remainder & used as an index to write from the base, 
	//gives the char in the largest (leftmost) place. Exiting the last recursion 
	//& taking another remainder gets the next place, and so on, until remainder 
	//is taken from original (full) number & whole number has been written. 
	//Debug a base 10 function if you need a visual reminder
	if (ptr >= 16)
		count += convert_hex(ptr / 16);
		//Divide by 16 b/c there are 16 chars in hex
		//"count +=" takes into account count from deepest level of recursion 
		//each time a level resolves and gives count as return value
	count += write(1, &base[ptr % 16], 1);
	return (count);
}

int	ft_printptr(uintptr_t ptr)
{
	int		count;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	count = 0;
	count += write(1, "0x", 2);
	//adding "0x" prefix to mem address is a convention used by GCC/Clang to
	//make it clear to humans thatthis is a mem address given in hex, but CPU
	//doesn't use it internally, so we need to add it 
	count += convert_hex(ptr);
	return (count);
}
/*
int	main(void)
{
	int	i;
	int	*ptr;
	int	result;

	i = 42;
	ptr = &i;
	//printf("ptr in unsigned long long is: %"PRIxPTR"\n", ptr);
	//- to see how mem address prints w/o %p format specifier
	result = ft_printptr((uintptr_t)ptr);
	write(1, "\n", 1);
	printf("ft_printptr result is: %i\n", result);
	result = printf("%p\n", ptr);
	printf("printf result is: %i\n", result);
	return (0);
}*/
