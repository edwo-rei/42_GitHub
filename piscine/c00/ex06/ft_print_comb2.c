/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_ft_printcomb2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:02:12 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/25 11:34:51 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_n(int i)//print function prints chars based on int conditions
{
	char	n;

	if (i < 10)
	{
		n = i + 48;//ascii conversion
		write(1, "0", 1);//tens place is always 0
		write(1, &n, 1);
	}
	else
	{
		n = (i / 10) + 48;//divide by 10 to get the tens place
		write(1, &n, 1);
		n = i % 10 + 48;//get the remainder for the ones place
		write(1, &n, 1);
	}
}

void	ft_print_comb2(void)
{
	int	a;//define int variables for each number (left & right)
	int	b;

	a = 0;
	while (a <= 98)//max poss value for a
	{
		b = a + 1;//b must always be greater than a
		while (b <= 99)
		{
			print_n(a);
			write(1, " ", 1);//add a space between #s
			print_n(b);
			if (!(a == 98 && b == 99))
				write(1, ", ", 2);//add a comma & space if not the last pair
			b++;
		}
		a++;
		b = 0;
	}
}
