/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orig_ft_print_comb2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:02:12 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/25 11:01:12 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    print_n(int i)
{
        char n;

	if (i<10)
	{
                n = i + 48;
		write(1, "0", 1);
		write(1, &n, 1);
	}
	else
	{
		n = (i / 10) + 48;
		write(1, &n, 1);
		n = i % 10 + 48;
		write(1, &n, 1);
	}
}

void    ft_print_comb2(void)
{
        int    place[2];

        place[0] = 0;
	while (place[0] <= 98)
	{
		place[1] = place[0] + 1;
		while (place[1] <= 99)
		{
			print_n(place[0]);
			write(1, " ", 1);
			print_n(place[1]);
			if (!(place[0] == 98 && place[1] == 99))
					write(1, ", ", 2);
			place[1]++;
		}
		place[0]++;
		place[1] = 0;
	}
}
