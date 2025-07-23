/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:45:32 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/23 20:04:16 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks to make sure each char in each arg is a pos or neg #. Done w/ 2 index
// vars b/c moving the argv ptr (i.e., *argv[i]++) caused my test prog to show 
//all 0s.
void	check_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			//advance past +/-
			if (argv[i][j] == '+' || argv[i][j] == '-')
				j++;
			//if followed by anything besides digit, print Error
			if (!argv[i][j])
				print_error();
			//loop thru remaining chars & print error for anything
			//besides a digit
			while (argv[i][j])
			{
				if (argv[i][j] < '0' || argv[i][j] > '9')
					print_error();
			j++;
			}
		}
		i++;
	}
}
