/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:51:52 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/11/14 14:31:12 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit(1);
}

void	error_free_maps(t_map *map, char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	if (map->grid)
		free_matrix(map, map->grid);
	if (map->check)
		free_matrix(map, map->check);
	exit(1);
}


//init game w/ NULL for ptrs to ensure functioning of close_window, set other
//calues to 0
void	init_game(t_mlx_data *data, char *path)
{
	data->mlx = NULL;
	data->window = NULL;
	data->img_ptr = NULL;
	data->base.img = NULL;
	data->wall.img = NULL;
	data->coin.img = NULL;
	data->player.img = NULL;
	data->exit.img = NULL;
	data->map.path = path;
	data->map.width = 0;
	data->map.height = 0;
	data->map.grid = NULL;
	data->map.check = NULL;
	data->map.collectibles = 0;
	data->map.check_collect = 0;
	data->map.exits = 0;
	data->moves = 0;
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