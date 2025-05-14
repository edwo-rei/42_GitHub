/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:48:23 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/09 20:41:48 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
*/
int	ft_iterative_factorial(int nb)
{
	int	ct;

	ct = nb;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
	{
		while (ct > 1)
		{
			nb *= ct - 1;
			ct--;
		}
		return (nb);
	}
}
/*
int	main(void)
{
	printf("%i\n", ft_iterative_factorial(4));
	printf("%i\n", ft_iterative_factorial(1));
	printf("%i\n", ft_iterative_factorial(0));
	printf("%i\n", ft_iterative_factorial(-1));
	return (0);
}*/
