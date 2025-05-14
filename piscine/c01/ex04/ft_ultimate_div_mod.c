/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:26:24 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/26 18:14:44 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	quotient;
	int	remainder;

	quotient = *a / *b;
	remainder = *a % *b;
	*a = quotient;
	*b = remainder;
}
/*
int   main(void)
{
        int     w;
        int     x;
        int*    y;
        int*    z;

        w = 9;
        x = 4;
        y = &w;
        z = &x;

        ft_ultimate_div_mod(y, z);
        printf("%i\n", *y);
        printf("%i\n", *z);
}*/
