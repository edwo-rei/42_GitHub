/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:56:33 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/11/13 14:23:39 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//load images of sprites. This MALLOCs, may cause leaks b/c previous image whose
//address is stored in img_ptr is never freed
void	load_sprites(t_mlx_data *data)
{
	data->base.img = mlx_xpm_file_to_image(data->mlx, "images/tile.xpm", 
			&data->base.width, &data->base.height);
	data->wall.img = mlx_xpm_file_to_image(data->mlx, "images/bricks.xpm", 
			&data->wall.width, &data->wall.height);
	data->player.img = mlx_xpm_file_to_image(data->mlx, "images/player.xpm", 
			&data->wall.width, &data->wall.height);
	data->coin.img = mlx_xpm_file_to_image(data->mlx, "images/coin.xpm", 
			&data->coin.width, &data->coin.height);
	data->exit.img = mlx_xpm_file_to_image(data->mlx, "images/exit.xpm", 
			&data->exit.width, &data->exit.height);
}

//loop thru the grid matrix, putting the proper image to the window in each 
//place depending on the char that is in the corresponding grid spot 
int	render_map(t_mlx_data *data)
{
	//initialize vars for x & y
	size_t	x;
	size_t	y;

	//set x & y to 0
	x = 0;
	y = 0;
	while (y < data->map.height * SIZE)
	{
		while (x < data->map.width * SIZE)
		{
			if ((x / SIZE) == data->map.player_pos.x 
					&& (y / SIZE) == data->map.player_pos.y)
				mlx_put_image_to_window(data->mlx, data->window,
				data->player.img, x, y);
			else if (data->map.grid[y / SIZE][x / SIZE] == '1')
				mlx_put_image_to_window(data->mlx, data->window,
				data->wall.img, x, y);
			else if (data->map.grid[y / SIZE][x / SIZE] == '0'
					|| data->map.grid[y / SIZE][x / SIZE] == 'P')
				mlx_put_image_to_window(data->mlx, data->window,
				data->base.img, x, y);
			else if (data->map.grid[y / SIZE][x / SIZE] == 'C')
				mlx_put_image_to_window(data->mlx, data->window,
				data->coin.img, x, y);
			else if (data->map.grid[y / SIZE][x / SIZE] == 'E')
				mlx_put_image_to_window(data->mlx, data->window,
				data->exit.img, x, y);
			x += SIZE;
		}
		x = 0;
		y += SIZE;
	}
	return (0);
}

//move player to new pos if not a wall, print move count, register collect & 
//close on exit (if all collects have been made)
void	move_player(t_mlx_data *data, size_t x, size_t y)
{
	if (data->map.grid[y][x] != '1')
	{
		data->map.player_pos.x = x;
		data->map.player_pos.y = y;
		ft_printf("Moves made: %i\n", ++data->moves);
	}
	if (data->map.grid[y][x] == 'C')
	{
		data->map.collectibles++;
		data->map.grid[y][x] = '0';
	}
	if ((data->map.grid[y][x] == 'E') 
			&& (data->map.collectibles == data->map.check_collect))
	{
		ft_printf("Game completed in %i moves\n", data->moves);
		close_window(data);
	}
}