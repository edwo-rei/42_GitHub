/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:39:50 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/09 20:16:59 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_hex(uintptr_t ptr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (ptr >= 16)
		count += convert_hex(ptr / 16);
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
	count += convert_hex(ptr);
	return (count);
}
