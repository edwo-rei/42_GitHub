/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:44:20 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/09 18:29:34 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb % i == 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
		i++;
		return ft_is_prime (nb);
}

int	main(void)
{
	printf("%i\n", ft_is_prime(3));
	printf("%i\n", ft_is_prime(4));
	printf("%i\n", ft_is_prime(5));
	printf("%i\n", ft_is_prime(6));
	return (0);
}
