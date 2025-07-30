/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:45:32 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/30 12:33:13 by edwo-rei         ###   ########.fr       */
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

/*void	check_digits(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		//advance past +/-
		if (*argv[i] == '+' || *argv[i] == '-')
			argv[i]++;
		//if followed by anything besides digit, print Error
		if (!*argv[i])
			print_error();
		//loop thru remaining chars & print error for anything
		//besides a digit
		while (*argv[i])
		{
			if (*argv[i] < '0' || *argv[i] > '9')
				print_error();
			argv[i]++;
		}
		i++;
	}
}*/

//checks to see if any arg is the same as another arg
void	check_doubles(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;
	int	l;
	
	i = 0;
	//while there are args
	while (i < argc - 1)
	{
		j = i + 1;
		k = 0;
		l = 0;
		//while there are args to compare current arg w/
		while (j < argc)
		{
			//skip over +s
			if (argv[i][k] == '+')
				k++;
			if (argv[j][l] == '+')
				l++;
			//skip over any 0s preceeded by +/- or any kind of space
			if ((argv[i][k] == '0') && (argv[i][k - 1] < '0'))
				k++;
			if ((argv[j][l] == '0') && (argv[j][l - 1] < '0'))
				l++;
			//if the 2 args are the same & NULL char has been reached
			if (argv[i][k] == 0 && argv[j][l] == 0)
				print_error();
			//if the 2 args are the same, check next char
			else if (argv[i][k] == argv[j][l])
			{
				k++;
				l++;
			}
			//if the 2 args are diff, move to next arg 
			else
			{
				k = 0;
				l = 0;
				j++;
			}
		}
		i++;
	}
}

/*This version of check_doubles moves the adresses pointed to be by the ptrs
in char **argv & causes problems, even though ChatGPT said ptr location outside
of a function shouldn't be affected by manipulation w/in a function
void	check_doubles(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	//while there are args
	while (i < argc - 1)
	{
		j = i + 1;
		//while there are args to compare current arg w/
		while (j < argc)
		{
			if (*argv[i] == '+')
				argv[i]++;
			if (*argv[j] == '+')
				argv[j]++;
			//if the 2 args are the same & NULL char has been reached
			if (*argv[i] == 0 && *argv[j] == 0)
				print_error();
			//if the 2 args are the same, check next char
			else if (*argv[i] == *argv[j])
			{
				argv[i]++;
				argv[j]++;
			}
			//if the 2 args are diff, move to next arg
			else
				j++;
		}
		i++;
	}
}*/

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
	/*int	i;
	
	i = 0;*/
	check_digits(argc, argv);
	/*while (i < argc)
	{
		printf("i: %i  loc: %p\n", i, argv[i]);
		i++;
	}*/
	check_doubles(argc, argv);
	/*i = 0;
	while (i < argc)
	{
                printf("i: %i  loc: %p\n", i, argv[i]);
				i++;
	}*/
	check_max(argc, argv);
}
