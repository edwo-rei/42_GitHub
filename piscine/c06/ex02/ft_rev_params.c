/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:10:41 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/10 14:03:39 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = argc - 1;//to intialize count at last arg
	j = 0;
	if (argc > 1)
	{
		while (i > 0)//loop will end when it arrives at first arg (0 pos)
		{
			while (argv[i][j] != '\0')
			{
				write(1, &argv[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i--;//to move to preceding arg
			j = 0;
		}
	}
	return (0);
}
