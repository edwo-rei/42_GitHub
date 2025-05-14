/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:57:01 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/24 16:48:25 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_n(char place[])
{
	if (place[0] == '7' && place[1] == '8' && place[2] == '9')
		write(1, place, 3);
	else if (place[1] > place[0] && place[2] > place[1])
	{
		write(1, place, 3);
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	place[3];

	place[0] = '0';
	place[1] = '1';
	place[2] = '2';
	while (place[0] <= '7')
	{
		while (place[1] <= '8')
		{
			while (place[2] <= '9')
			{
				print_n(place);
				place[2]++;
			}
			place[1]++;
			place[2] = 0;
		}
		place[0]++;
		place[1] = 0;
	}
}
