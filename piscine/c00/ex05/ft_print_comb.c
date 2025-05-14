/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:57:01 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/24 20:02:10 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_n(char a, char b, char c)//utility function that writes the 3 appropriate digits. Does not have a return value ("void"), takes the characters a, b, & c as parameters
{
	if (b > a && c > b)//only print if each digit is greater than the one to its left
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
		if (!(a == '7' && b == '8' && c == '9'))
			write(1, ", ", 2);//adds a space if not the last possible combination
	}
}

void	ft_print_comb(void)
{
	char	a;//create char variables for each of the 3 digits and their while loops
	char	b;
	char	c;

	a = '0';//initialize them to show the lowest possible combo
	b = '1';
	c = '2';
	while (a <= '7')//while loops run up to to the highest digit for that place
	{
		while (b <= '8')
		{
			while (c <= '9')
			{
				print_n(a, b, c);
				c++;//try the print function with each # in the ones place (will only write if conditions are met)
			}
			b++;//increase the tens place by 1 (e.g., from 09 to 10)
			c = 0;//reset the ones place
		}
		a++;//increase hundreds place
		b = 0;//reset the tens place
	}
}
