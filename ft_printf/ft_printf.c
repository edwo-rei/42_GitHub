/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:03:22 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/16 19:43:36 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#insert "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	int	i;
	int	count;//will need to count # of args somehow
	va_list	args;

	//initialize va_list
	va_start(args, s);
	count = va_arg(args, /*type of variable*/);
	i = 0;
	while(count != NULL)
	{
		count = va_arg(args, /*type of var*/);
	}
	//call va_end once done processing list
	va_end(args);
}

int	main(void)
{
	int	result;
}
