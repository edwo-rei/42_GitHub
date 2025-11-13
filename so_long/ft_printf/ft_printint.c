/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:23:29 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/09 20:16:45 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int n)
{
	char	reverse[12];
	int		i;
	int		count;
	long	ln;

	i = 0;
	count = 0;
	ln = n;
	if (ln == 0)
		count += write(1, "0", 1);
	if (ln < 0)
	{
		count += write(1, "-", 1);
		ln *= -1;
	}
	while (ln != 0)
	{
		reverse[i++] = (ln % 10) + 48;
		ln /= 10;
	}
	while (i > 0)
		count += write(1, &reverse[--i], 1);
	return (count);
}
