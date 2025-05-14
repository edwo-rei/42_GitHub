/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:02:12 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/24 20:27:56 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    print_n(char a, char b, char c, char d)
{
        if (b > a && c > b)
        {
                write(1, &a, 1);
                write(1, &b, 1);
		write(1, " ", 1);
                write(1, &c, 1);
		write(1, &d, 1);
                if (!(a == '9' && b == '8' && c == '9' && d == '9'))
                        write(1, ", ", 2);
        }
}

void    ft_print_comb2(void)
{
        char    a;
        char    b;

        a = '0';
        b = '0';
	while (a <= 9)
	{
		while (b <= 9)
		{
			print_n(a, b, c, d);
			b++;
		}
		a++;
		b = 0;
	}
}
