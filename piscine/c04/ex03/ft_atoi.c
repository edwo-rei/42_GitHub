/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:05:16 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/07 19:58:15 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdlib.h>
#include <stdio.h>
*/
int	ft_atoi(char *str)
{
	int	nb;
	int	neg;

	nb = 0;
	neg = 0;
	while ((9 <= *str && *str <= 13) || (*str == 32))
		str++;
	while ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
		{
			neg++;
		}
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		nb = nb * 10;
		nb = nb + (*str - 48);
		str++;
	}
	if (neg % 2 > 0)
		return (-nb);
	return (nb);
}
/*
int	main(void)
{
	char	str[] = "   ---+--+1234ab567";

	printf("%i\n", ft_atoi(str));
}*/
