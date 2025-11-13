/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:43:57 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/10/30 14:13:37 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//improved pixel put to avoid slow rendering calcul
void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int				offset;
	//b/c a char occupies 1 byte, chars are the right data type for direct mem
	//manipulation b/c ptr math moves 1 byte at a time
	char 			*pixel_byte_ptr;
	unsigned int	*pixel_unint_ptr;

	//calculate mem offset based on line_len. BPP divided by 8 to convert bits 
	//to bytes so we can do ptr math. If this isn't done, nothing shows, even
	//if x & y are 0
	offset = (img->line_len * y) + (x * (img->bpp / 8));
	//go to img.pixel_data address & move ptr forward by offset bytes so it
	//points to pixel at x, y in image buffer. Set to pixel_byte_ptr 
	pixel_byte_ptr = img->pixel_data + offset;
	//Then cast resulting char ptr to unsigned int ptr (type used 4 color)
	pixel_unint_ptr = (unsigned int *)pixel_byte_ptr; 
	//Then dereference that ptr & set it to the color given as a parameter
	*pixel_unint_ptr = color;
}

//paint the screen the color given as a parameter
void	paint_win(t_mlx_data *data, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WIN_HT)
	{
		while (x < WIN_WI)
		{
			my_pixel_put(&data->img, x, y, color);
			x++;
		}
		y++;
		x = 0;
	}
}

//func destroys image, window & display struct, frees ptr to mlx. May need to
//as if statements to check if ptrs exist
int	close_window(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

//func interprets keystrokes & if ESC pressed, cleans up & closes window
int	input_handler(int keysym, t_mlx_data *data)
{
	int	width = 64;
	int	height = 64;
	
	if (keysym == XK_Escape)
		close_window(data);
	else if (keysym == XK_r)
		paint_win(data, 0xff0000);
	else if (keysym == XK_g)
		paint_win(data, 0xff00);
	else if (keysym == XK_b)
		paint_win(data, 0xff);
	else if (keysym == XK_i)
		data->img.img_ptr = mlx_xpm_file_to_image(data->mlx, "./images/player.xpm", 
			&width, &height);
	//this func is what puts the img to the window. Need to use repeatedly to draw map
	//according to what is in each grid squard. Must also figure out how to create .ber
	//map file
	mlx_put_image_to_window(data->mlx, data->window, 
				data->img.img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	//initialize a structure to hold map vars
	t_mlx_data	data;
	
	//if no args provided, return an error
	//if (argc != 2)
		//return error
	//establish a connection to the graphical system (MLX) & return void 
	//ptr to location of current MLX instance - mlx_init() MALLOCs!
	data.mlx = mlx_init();
	//return error if init fails
	if (data.mlx == NULL)
		return (1);
	//parse input map
	//open a window  for the game & return ptr to loc - also MALLOCs!
	data.window = mlx_new_window(data.mlx, WIN_WI, WIN_HT, WIN_NAME);
	//free all & return error if new window fails
	if (data.window == NULL)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (1);
	}
	//create an image to buffer pixels
	data.img.img_ptr = mlx_new_image(data.mlx, WIN_WI, WIN_HT);
	//get image data
	data.img.pixel_data = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	//key hook to interpret keystrokes w/ func input_handler
	mlx_key_hook(data.window, input_handler, &data);
	//hook to interpret clicking on the window's X button. 17 is the event
	//code for the window close event (DestroyNotify), which has no mask
	//requirement, which is why we just use 0 as a place holder
	mlx_hook(data.window, 17, 0, close_window, &data);
	// mlx_loop_hook needed to continuously render the game space?
	//create an event loop to keep window open & wait for input
	mlx_loop(data.mlx);

	// CLEAN UP never actually reached b/c of loop
	//mlx_destroy_window(data.mlx, data.window);
	// destroy display
	//mlx_destroy_display(data.mlx);
	// free ptr to display struct
	//free(data.mlx);
}
