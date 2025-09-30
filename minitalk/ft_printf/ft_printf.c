/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:03:22 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/09/30 14:00:47 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (type == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (type == 'p')
		count += ft_printptr(va_arg(args, uintptr_t));
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
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str != '%')
			count += write(1, str, 1);
		else
			count += check_format(*++str, args);
		str++;
	}
	va_end(args);
	return (count);
}
