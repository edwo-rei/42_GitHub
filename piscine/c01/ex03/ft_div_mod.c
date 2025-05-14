/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:35:10 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/26 17:22:35 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	quotient;
	int	remainder;

	quotient = a / b;
	remainder = a % b;
	*div = quotient;
	*mod = remainder;
}

/*int	main(void)
{
	int	w;
	int	x;
	int*	y;
	int*	z;

	w = 0;
	x = 1;
	y = &w;
	z = &x;

	ft_div_mod(9, 2, y, z);
	printf("%i\n", *y);
	printf("%i\n", *z);
}*/
