/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:29:58 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/20 13:39:54 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunint(unsigned int n)
{
	char	reverse[11];
	//for 4294967295 + '\0'
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
		count += write(1, "0", 1);
	while (n != 0)
	{
		reverse[i++] = (n % 10) + 48;
		//will first assign ASCII of # to reverse[i], then increase i by 1
		n /= 10;
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
	unsigned int	n;
	int	result;

	n = 4294967295;
	result = ft_printunint(n);
	write(1, "\n", 1);
	printf("return value: %i\n", result);
	result = printf("%u\n", n);
	printf("printf return value: %i\n", result);
}*/
