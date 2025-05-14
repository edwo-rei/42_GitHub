/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:37:25 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/10 13:58:48 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;//counter variable for args
	j = 0;//count w/in each arg to write string
	if (argc > 1)//must have at least one arg
	{
		while (i < argc)//loop runs through last arg (1 less than argc b/c first pos = 0)
		{
			while (argv[i][j] != '\0')//write chars from each string
			{
				write(1, &argv[i][j], 1);
				j++;
			}
			write(1, "\n", 1);//newline after each string
			i++;//move to next arg
			j = 0;//reset count w/in string
		}
	}
	return (0);
}
