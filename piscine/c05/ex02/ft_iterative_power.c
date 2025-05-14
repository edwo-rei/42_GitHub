/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:15:35 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/09 20:54:34 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
*/
int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		while (power > 1)
		{
			nb *= i;
			power--;
		}
		return (nb);
	}
}
/*
int	main(void)
{
	printf("%i\n", ft_iterative_power(3, 3));
	printf("%i\n", ft_iterative_power(3, 0));
	printf("%i\n", ft_iterative_power(0, 0));
	printf("%i\n", ft_iterative_power(2, -2));
	return (0);
}*/
