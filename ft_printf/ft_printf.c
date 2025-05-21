/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:03:22 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/21 13:56:00 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_printchar(va_arg(args, int));//int, not char, b/c char is automatically promoted
	else if (type == 's')
		count += ft_printstr(va_arg(args, char *));
	/*else if (type == 'p')
		count += print_ptr(va_arg(args, unsigned long long));*/
	else if (type == 'd' || type == 'i')
		count += ft_printint(va_arg(args, int));
	else if (type == 'u')
		count += ft_printunint(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		count += ft_printhex(va_arg(args, unsigned int), type);
	else if (type == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int	count;
	va_list	args;

	//initialize va_list
	va_start(args, str);
	count = 0;
	while(*str)
	{
		if (*str != '%')
			count += write(1, str, 1);//assuming use of ptr & not index
		else
			count += check_format(*++str, args);//helper function for % using va_arg, ++str
		str++;
	}
	//call va_end once done processing list
	va_end(args);
	return (count);//return # of chars of outpust str
}

int	main(void)
{
	int		result;
	unsigned int	n;
	char		str[] = "John Jacob Jingleheimer Schmidt";

	n = 4294967295;
	result = ft_printf("Hello, %s, I've seen you %x times\n", str, n);
	printf("ft_printf return value: %i\n", result);
	result = printf("Hello, %s, I've seen you %x times\n", str, n);
	printf("printf return value: %i\n", result);
}
