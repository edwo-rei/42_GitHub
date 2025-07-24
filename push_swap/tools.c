/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:33:26 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/24 19:29:49 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long	long_atoi(const char *str)
{
	int	i;
	long	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((9 <= str[i] && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		n *= 10;
		n += str[i] - 48;
		i++;
	}
	return (n * sign);
}
/*
int	main(void)
{
	char	pos[] = "2000247483650";
	char	neg[] = "-10247483658";
	char	mix[] = "	-2468tx";
	char	empty[] = "";

	printf("atoi pos: %i\n", atoi(pos));
	printf("long_atoi pos: %li\n", long_atoi(pos));
	printf("atoi neg: %i\n", atoi(neg));
	printf("long_atoi neg: %li\n", long_atoi(neg));
	printf("atoi mix: %i\n", atoi(mix));
	printf("long_atoi mix: %li\n", long_atoi(mix));
	printf("atoi empty: %i\n", atoi(empty));
	printf("long_atoi empty: %li\n", long_atoi(empty));
}*/
