/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:20:00 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/11/11 13:40:32 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//func to free mem allocated to check matrix used for validate_path
void	free_check(t_map *map)
{
	size_t	i;
	
	i = 0;
	while (i < map->height)
	{
		free(map->check[i]);
		map->check[i] = NULL;
		i++;
	}
	free(map->check);
	map->check  = NULL;
}

//recursive function to check map for valid paths to all Cs & E from start pos
void	validate_path(t_map *map, size_t pos_y, size_t pos_x)
{
	size_t	x;
	size_t	y;

	x = pos_x;
	y = pos_y;
	//base condition: check if current pos is out of bounds (>= b/c 1st spot is
	// 0, so last spot is map height/width - 1); check if current pos is a wall;
	//check if current pos has already been checked
	if (y < 0 || x < 0 || y >= map->height || x >= map->width
			|| map->grid[y][x] == '1' || map->check[y][x] == '1')
		return;
	//mark current cell as already checked
	map->check[y][x] = '1';
	if (map->grid[y][x] == 'E')
		map->exits++;
	if (map->grid[y][x] == 'C')
		map->check_collect++;	
	//recursively fill cells above, below, left & right
	validate_path(map, y - 1, x);//check cell above
	validate_path(map, y + 1, x);//check cell below
	validate_path(map, y, x - 1);//check cell to left
	validate_path(map, y, x + 1);//check cell to right
	return ;
}
