/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:11:24 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/05 14:21:23 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 0;
	while ((9 <= str[i] && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		n *= 10;
		n += str[i] - 48;
		i++;
	}
	if (sign % 2 != 0)
		return (-n);
	return (n);
}
/*
int	main(void)
{
	char	pos[] = "+-12345";
	char	neg[] = "--6789";
	char	mix[] = "	-2468tx";
	char	empty[] = "";

	printf("atoi pos: %i\n", atoi(pos));
	printf("ft_atoi pos: %i\n", ft_atoi(pos));
	printf("atoi neg: %i\n", atoi(neg));
	printf("ft_atoi neg: %i\n", ft_atoi(neg));
	printf("atoi mix: %i\n", atoi(mix));
	printf("ft_atoi mix: %i\n", ft_atoi(mix));
	printf("atoi empty: %i\n", atoi(empty));
	printf("ft_atoi empty: %i\n", ft_atoi(empty));
}*/
