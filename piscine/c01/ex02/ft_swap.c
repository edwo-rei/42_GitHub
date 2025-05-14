/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:39:21 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/26 18:17:16 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)//takes 2 pointers to int variables as parameters
{
	int	content_a;//creates 2 int variables
	int	content_b;

	content_a = *a;//assigns them the values held in the memory addresses referred to by the 2 pointers
	content_b = *b;
	*a = content_b;//then assigns the mem addresses held by the ptrs w/ the values held by int variables, but reverses the order
	*b = content_a;
}
/*
int	main(void)
{
	int	i;
	int	j;
	int*	address_i;
	int*	address_j;

	i = 17;
	j = 42;
	address_i = &i;
	address_j = &j;

	ft_swap(address_i, address_j);
	printf("%i\n", *address_i);
	printf("%i\n", *address_j);
}*/
