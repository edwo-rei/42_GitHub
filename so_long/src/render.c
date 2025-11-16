/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:56:33 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/11/15 14:34:27 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	if (!data->base.img || !data->wall.img || !data->player.img
		|| !data->coin.img || !data->exit.img)
	{
		error_warn("File to image failed");
		clean_up(data);
	}
}

//loop thru the grid matrix, putting the proper image to the window in each 
//place depending on the char that is in the corresponding grid spot 
void	draw_map(t_mlx_data *data)
{
	t_point	g;
	char	*s;

	g.x = 0;
	g.y = 0;
	while (g.y < data->map.height * SZ)
	{
		while (g.x < data->map.width * SZ)
		{
			if ((g.x / SZ) == data->map.p1.x && (g.y / SZ) == data->map.p1.y)
				s = data->player.img;
			else if (data->map.grid[g.y / SZ][g.x / SZ] == '1')
				s = data->wall.img;
			else if (data->map.grid[g.y / SZ][g.x / SZ] == '0')
				s = data->base.img;
			else if (data->map.grid[g.y / SZ][g.x / SZ] == 'C')
				s = data->coin.img;
			else if (data->map.grid[g.y / SZ][g.x / SZ] == 'E')
				s = data->exit.img;
			mlx_put_image_to_window(data->mlx, data->window, s, g.x, g.y);
			g.x += SZ;
		}
		g.x = 0;
		g.y += SZ;
	}
}

int	render_map(t_mlx_data *data)
{
	draw_map(data);
	return (0);
}

//move player to new pos if not a wall, print move count, register collect & 
//close on exit (if all collects have been made). Changes P & Cs to 0 after
//contact
void	move_player(t_mlx_data *data, size_t x, size_t y)
{
	if (data->map.grid[y][x] != '1')
	{
		if (data->moves == 0)
			data->map.grid[data->map.p1.y][data->map.p1.x] = '0';
		data->map.p1.x = x;
		data->map.p1.y = y;
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
		clean_up(data);
	}
}

//func interprets keystrokes & if ESC pressed, cleans up & closes window
int	input_handler(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		clean_up(data);
	else if (keysym == XK_w)
		move_player(data, data-> map.p1.x, data->map.p1.y - 1);
	else if (keysym == XK_s)
		move_player(data, data-> map.p1.x, data->map.p1.y + 1);
	else if (keysym == XK_a)
		move_player(data, data-> map.p1.x - 1, data->map.p1.y);
	else if (keysym == XK_d)
		move_player(data, data-> map.p1.x + 1, data->map.p1.y);
	return (0);
}
