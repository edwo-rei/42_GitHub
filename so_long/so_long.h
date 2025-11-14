/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:49:58 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/11/14 14:31:50 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* INCLUDE GUARD */
#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_WI 1000
# define WIN_HT 1000
# define WIN_NAME "so_long"
# define SIZE 64

/* LIBRARIES */
//stdlib contains malloc, free & exit
# include <stdlib.h>
//unistd library contains read & close
# include <unistd.h>
//stdio library contains perror & strerror
# include <stdio.h>
//file control library contains open
# include <fcntl.h>
//X11 keysym library contains abstract representations of keys ued for key hook
# include <X11/keysym.h>

/* MY HEADER FILES */
//lib_ft header file contains prototypes of my libft functions
# include "libft/libft.h"
//ft_printf header file contains prototypes of my ft_printf functions
# include "ft_printf/ft_printf.h"
//gnl header file contains prototype of my get_next_line function
# include "gnl/get_next_line.h"
//mlx header file contains prototypes of MiniLibX functions
# include "mlx/mlx.h"

//struct for coordinates
typedef struct s_point
{
	size_t	x;
	size_t	y;
}		t_point;

//struct for sprites
typedef struct s_sprite
{
	char	*img;
	int		width;
	int		height; 
}			t_sprite;

typedef struct s_map
{
	char	*path;
	size_t	width;
	size_t	height;
	char	**grid;
	char	**check;
	t_point	player_pos;
	int		collectibles;
	int		check_collect;
	int		exits;
}			t_map;

//struct for data for the current instance of the game & window
typedef struct s_mlx_data
{
	void		*mlx;
	void		*window;
	void		*img_ptr;
	char		*pixel_data;
	int			bpp;
	int			line_len;
	int			endian;
	//endianness: order bytes arranged in mem; big = MSB 1st, little = LSB 1st
	t_map		map;
	t_sprite	base;
	t_sprite	wall;
	t_sprite	coin;
	t_sprite	player;
	t_sprite	exit;
	int			moves;
}			t_mlx_data;

void	init_game(t_mlx_data *data, char *path);
void	error_msg(char *msg);
void	error_free_maps(t_map *map, char *msg);
size_t	ft_linelen(const char *s);
int		check_map_name(char *name);
void	measure_map(t_map *map);
void	parse_map(t_map *map);
void	validate_path(t_map *map, size_t pos_y, size_t pos_x);
void	free_check(t_map *map);
void	free_matrix(t_map *map, char **matrix);
void	load_sprites(t_mlx_data *data);
int		render_map(t_mlx_data *data);
int		input_handler(int keysym, t_mlx_data *data);
void	move_player(t_mlx_data *data, size_t x, size_t y);
int		close_window(t_mlx_data *data);

#endif
