/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:01:53 by mapascua          #+#    #+#             */
/*   Updated: 2025/03/31 17:10:56 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	free_maps(int **map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_error(int mem, int **map, int **views)//in case of error, free up memory allocated
{
	if (mem == 1)
		free_maps(map);
	if (mem == 2)
	{
		free_maps(map);
		free_maps(views);
	}
	write(1, "Error", 5);
	return (0);
}

int	ft_strlen(char *str)//measure string length
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	validate_input(char *str)//makes sure input string is valid (right quantity of #s in right places)
{
	int	i;

	i = 0;
	if (ft_strlen(str) != 31)//input string must occupy 31 places (16 characters & 15 spaces in between)
		return (-1);
	while (str[i])
	{
		if ((str[i] < '1' || str[i] > '4') && str[i] != ' ')// nothing besides #s 1-4 & spaces
			return (-1);
		if (i % 2 == 0 && (str[i] < '1' || str[i] > '4'))//#s in right places
			return (-1);
		if (i % 2 == 1 && str[i] != ' ')//spaces in right places
			return (-1);
		i++;
	}
	return (0);
}
