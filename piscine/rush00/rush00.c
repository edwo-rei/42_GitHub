/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 11:39:50 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/22 17:18:21 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	i = 0;
int	j = 0;
char	corner = 'o';
char	dash = '-';
char	bar = '|';
char	space = ' ';
char	enter = '\n';

void	rush(int x, int y)
{
	while (i < x)
	{
		while (j < y)
		{
			if ((i == 0 || i == x - 1) && (j == 0 || j == y - 1))
			{
				write(1, &corner, 1);
			}
			else if (i == 0 || i == x - 1)
			{
				write(1, &dash, 1);
			}
			else if (j == 0 || j == y - 1)
			{
				write(1, &bar, 1);
			}
			else
			{
				write(1, &space, 1);
			}
			j++;
		}
		write (1, &enter, 1);
		j = 0;
		i++;
	}
}

int main(void)
{
	rush(4, 4);
}
