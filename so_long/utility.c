/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:51:52 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/11/07 12:23:47 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit(1);
}

size_t	ft_linelen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

//ft_strlen returns a size_t, which is why this func intializes i as a size_t,
//and lots of other map parsing funcs use size_t. size_t is an unsigned int
//type used for the result returned by the sizeof operator. size_t is chosen so that 
//it can store the maximum size of a theoretically possible array or an object
int	check_map_name(char *name)
{
	size_t	i;

	i  = ft_strlen(name) - 1;
	if (name[i - 4] && name[i - 3] == '.' && name[i - 2] == 'b'
			&& name [i - 1] == 'e' && name[i] == 'r')
		return (0);
	else
		return (1);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 2 || check_map_name(argv[1]))
			error_msg("Usage: ./so_long map_name.ber");
	printf("name works\n");
}*/