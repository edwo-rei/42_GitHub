/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:23:29 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/20 12:44:27 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int n)
{
	char	reverse[12];
	//size [12] to hold -2147483648 + '\0'
	int		i;
	int		count;
	long	ln;

	i = 0;
	count = 0;
	//long int necessary for -2147483648
	ln = n;
	if (ln == 0)
		count += write(1, "0", 1);
	if (ln < 0)
	{
		count += write(1, "-", 1);
		ln *= -1;
		//make positive (won't work with int -2147483648 b/c it will be turned into 
		//2147483648, which doesn't fit into range of integers. Pos #s in binary 
		//start w/ 0, as does 0, so there is 1 more # in neg direction.
	}
	while (ln != 0)
	{
		reverse[i++] = (ln % 10) + 48;
		//will first assign ASCII of # to reverse[i], then increase i by 1
		ln /= 10;
		//then divide # by 10 to remove digit in one's place
	}
	//i is 1 more than last index written(e.g. for "1234" i = 4)
	while (i > 0)
		count += write(1, &reverse[--i], 1);
		//i is decreased before place in array is dereferenced, so i = 0 when
		//writing in last loop. Count increased by 1 for each char written
	return (count);
}
/*
int	main(void)
{
	int	n;
	int	result;

	n = -2147483648;
	result = ft_printint(n);
	write(1, "\n", 1);
	printf("return value: %i\n", result);
	result = printf("%i\n", n);
	printf("printf return value: %i\n", result);
}*/
