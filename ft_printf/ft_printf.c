/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:03:22 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/22 13:20:50 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//helper function calls function corresponding to format indicated by char to
//print content indicated by variable in corresponding spot in va_list
static int	check_format(char type, va_list args)
{
	int	count;

	count = 0;
	
	if (type == 'c')
		count += ft_printchar(va_arg(args, int));
		//va_arg macro fetches next argument of type indicated (int) in list args
		//int, not char, b/c char is automatically promoted to int when calling
		//a variadic function. If left as char, would result in undefined 
		//behavior b/c va_arg expects an int w/ regards to memory. va_list is 
		//basically a ptr to a memory address, and va_arg must "know" how much to
		//advance to next address
	else if (type == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (type == 'p')
		count += ft_printptr(va_arg(args, uintptr_t));
		//uintptr_t is a type of unsigned int made to hold a ptr
	else if (type == 'd' || type == 'i')
		count += ft_printint(va_arg(args, int));
		//for printf purposes, no meaningful diff b/t 'd' & 'i'
	else if (type == 'u')
		count += ft_printunint(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		count += ft_printhex(va_arg(args, unsigned int), type);
	else if (type == '%')
		count += write(1, "%", 1);
	//return count of chars printed by helper function to ft_printf
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	//declare va_list type variable called "args" that points to current pos in
	//in that list. As of yet don't know how long list is.
	va_list	args;

	//initialize args and set it at point just after 1st parameter (str)
	va_start(args, str);
	count = 0;
	//run this while loop as long as current place in str has a char
	while (*str)
	{
		//just write the char & increase count by 1 as long as char
		//isn't a %
		if (*str != '%')
			count += write(1, str, 1);	
		//if current char is %, call helper function & increase count by
		//its return value. Helper function takes next char in str (++str)
		//as an argument
		else
			count += check_format(*++str, args);
		//move forward a place in str
		str++;
	}
	//call va_end macro once done processing list
	va_end(args);
	//return total # of chars printed (doesn't include '\0' at end of str)
	return (count);
}
/*
int	main(void)
{
	int		result;
	char		*str;

	str = "John Jacob Jingleheimer Schmidt";
	result = ft_printf("Hello, %s, your location is %p\n", str, str);
	printf("ft_printf return value: %i\n", result);
	result = printf("Hello, %s, your location is %p\n", str, str);
	printf("printf return value: %i\n", result);
}*/
