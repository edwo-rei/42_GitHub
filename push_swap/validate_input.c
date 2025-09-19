/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:45:32 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/09/19 14:16:12 by edwo-rei         ###   ########.fr       */
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
			//if followed by NULL char, print Error
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

//added this func b/c check_doubles was too long. It compares 2 args after skipping
//+s & 0s
int	compare_args(char *i, char *j)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	//skip over +s
	if (i[k] == '+')
		k++;
	if (j[l] == '+')
		l++;
	if (i[k] == '-' && j[l] == '-')
	{
		k++;
		l++;
	}
	//skip over any 0s preceeding digits
	while (i[k] == '0')
		k++;
	while (j[l] == '0')
		l++;
	//loop thru digits as long as they're equal & return TRUE if equal to end
	while (i[k] && j[l])
		if (i[k++] != j[l++])
			return (0);
	return (i[k] == 0 && j[l] == 0);
}

//checks to see if any arg is the same as another arg
void	check_doubles(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 0;
	//while there is an arg followed by at least one other
	while (i < argc - 1)
	{
		j = i + 1;
		//while there are args to compare current arg w/
		while (j < argc)
		{
			//compare args i & j, after +s & 0s
			if (compare_args(argv[i], argv[j]))
				print_error();
			j++;
		}
		i++;
	}
}

//checks to see if any number is outside the range of integers
void	check_max(int argc, char **argv)
{
	long int	n;
	int		i;

	i = 0;
	while (i < argc)
	{
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			print_error();
		i++;
	}
}

void	validate_input(int argc, char **argv)
{
	check_digits(argc, argv);
	check_doubles(argc, argv);
	check_max(argc, argv);
}
