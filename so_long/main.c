/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:43:57 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/11/13 13:30:01 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//func destroys image, window & display struct, frees ptr to mlx. May need to
//as if statements to check if ptrs exist
int	close_window(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx, data->img_ptr);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

//func interprets keystrokes & if ESC pressed, cleans up & closes window
int	input_handler(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	else if (keysym == XK_w)
		move_player(data, data-> map.player_pos.x, data->map.player_pos.y - 1);
	else if (keysym == XK_s)
		move_player(data, data-> map.player_pos.x, data->map.player_pos.y + 1);
	else if (keysym == XK_a)
		move_player(data, data-> map.player_pos.x - 1, data->map.player_pos.y);
	else if (keysym == XK_d)
		move_player(data, data-> map.player_pos.x + 1, data->map.player_pos.y);
	return (0);
}

int	main(int argc, char **argv)
{
	//initialize a structure to hold map vars
	t_mlx_data	data;
	
	//if no args provided or map name doesn't end in ".ber", return an error
	if (argc != 2 || check_map_name(argv[1]))
		error_msg("Usage: ./so_long folder/map_name.ber");
	//save the map name as the map path
	data.map.path = argv[1];
	data.moves = 0;
	//read the data from the map file & save it into a matrix
	parse_map(&data.map);
	//once the data is in the matrix, check to see if all map requirements are met
	//establish a connection to the graphical system (MLX) & return void 
	//ptr to location of current MLX instance - mlx_init() MALLOCs!
	data.mlx = mlx_init();
	//return error if init fails
	if (data.mlx == NULL)
		return (1);
	//open a window  for the game & return ptr to loc - also MALLOCs!
	data.window = mlx_new_window(data.mlx, data.map.width * SIZE, 
		data.map.height * SIZE, WIN_NAME);
	//free all & return error if new window fails
	if (data.window == NULL)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (1);
	}
	//create an image to buffer pixels. mlx_new_image MALLOCs!
	data.img_ptr = mlx_new_image(data.mlx, data.map.width * SIZE, 
		data.map.height * SIZE);
	//get image data
	data.pixel_data = mlx_get_data_addr(data.img_ptr, &data.bpp,
			&data.line_len, &data.endian);
	//load sprites
	load_sprites(&data);
	//key hook to interpret keystrokes w/ func input_handler
	mlx_key_hook(data.window, input_handler, &data);
	//hook to interpret clicking on the window's X button. 17 is the event
	//code for the window close event (DestroyNotify), which has no mask
	//requirement, which is why we just use 0 as a place holder
	mlx_hook(data.window, 17, 0, close_window, &data);
	// mlx_loop_hook needed to continuously render the game space
	mlx_loop_hook(data.mlx, render_map, &data);
	//create an event loop to keep window open & wait for input
	mlx_loop(data.mlx);

	// CLEAN UP never actually reached b/c of loop
	//mlx_destroy_window(data.mlx, data.window);
	// destroy display
	//mlx_destroy_display(data.mlx);
	// free ptr to display struct
	//free(data.mlx);
}
