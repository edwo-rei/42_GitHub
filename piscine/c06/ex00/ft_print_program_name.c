/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:15:14 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/10 13:55:11 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>//header includes library w/ write function

int	main(int argc, char **argv)//argc = argument count (begins at 1) & argv = argument vector, an array of strings (or matrix) in which each string is an arg
{
	int	i;//counter variable to run while loop

	i = 0;
	if (argc > 0)//errors obliged me to use argc
	{
		while (argv[0][i] != '\0')//1st argument (prog name), pos isn't null
		{
			write(1, &argv[0][i], 1);//write each char
			i++;
		}
		write(1, "\n", 1);//newline
	}
	return (0);
}
