/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:05:16 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/07 19:54:30 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	nb;
	int	neg;

	nb = 0;
	neg = 0;
	while ((9 <= *str && *str <= 13) || (*str == 32))
		str++;
	while((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
		{
			neg++;
		}
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		nb = nb * 10;//by multiplying current # by 10, we shift it a place to the left
		nb = nb + (*str - 48);//and then we add current digit to ones place
		str++;
	}
	if (neg % 2 > 0)
		return (-nb);
	return (nb);//returning nb, so advancing using *str isn't a problem
}

int	main(void)
{
	char	str[] = "   ---+--+1234ab567";
	int	i;

	printf("%i\n", ft_atoi(str));
	i = (ft_atoi(str)) / 10;
	printf("%i\n", i);
	/*
	printf("%i\n", atoi(str));
	i = (atoi(str)) / 10;
	printf("%i", i);*/
}
