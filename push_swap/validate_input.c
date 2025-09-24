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
void	check_digits(int count, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (args[i][j])
		{
			//advance past +/-
			if (args[i][j] == '+' || args[i][j] == '-')
				j++;
			//if followed by NULL char, print Error
			if (!args[i][j])
				print_error(count, args);
			//loop thru remaining chars & print error for anything
			//besides a digit
			while (args[i][j])
			{
				if (args[i][j] < '0' || args[i][j] > '9')
					print_error(count, args);
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
void	check_doubles(int count, char **args)
{
	int	i;
	int	j;
	
	i = 0;
	//while there is an arg followed by at least one other
	while (i < count - 1)
	{
		j = i + 1;
		//while there are args to compare current arg w/
		while (j < count)
		{
			//compare args i & j, after +s & 0s
			if (compare_args(args[i], args[j]))
				print_error(count, args);
			j++;
		}
		i++;
	}
}

//checks to see if any number is outside the range of integers
void	check_max(int count, char **args)
{
	long int	n;
	int		i;

	i = 0;
	while (i < count)
	{
		n = ft_atol(args[i]);
		if (n < INT_MIN || n > INT_MAX)
			print_error(count, args);
		i++;
	}
}

void	validate_input(int count, char **args)
{
	check_digits(count, args);
	check_doubles(count, args);
	check_max(count, args);
}
