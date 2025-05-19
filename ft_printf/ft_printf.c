/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:03:22 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/19 19:24:44 by edwo-rei         ###   ########.fr       */
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
		count += print_str(va_arg(args, char *));
	else if (type == 'p')
		count += print_ptr(va_arg(args, unsigned long long));
	else if (type == 'd')
		count += print_int(va_arg(args, int));
	else if (type == 'i')
		count += print_int(va_arg(args, int));
	else if (type == 'u')
		count += print_int(va_arg(args, unsigned int));
	else if (type == 'x')
		count += print_int(va_arg(args, unsigned int));
	else if (type == 'X')
		count += print_int(va_arg(args, unsigned int));
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
			count += write(1, str, 1);//assuming use of prt & not index
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
	int	result;
	char	str[] = "%you";

	/*result = ft_printf("Hello, %s\n", str);
	ft_printf("ft_printf return value: %i\n", result);*/
	result = printf("Hello, %k\n", str);
	printf("printf return value: %i\n", result);
}
