/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:50:23 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/25 19:23:44 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *nbr)//parameter must be a pointer to an int
{
	*nbr = 42;//dereference with * to set the value held at that memory address
}
/*
int main(void)
{
	int	i;
	i = 17;
	printf("%i\n", i);

	int* j = &i;
	printf("%d\n", *j);

	ft_ft(j);
	printf("%d\n", *j);

	ft_ft(&i);
	printf("%d\n", i);
}*/
