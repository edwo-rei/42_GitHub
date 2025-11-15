/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:46:50 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/11/15 12:35:35 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Map parsing tasks:
	- map file exists? OK
	- map file isn't empty? GIVES ERROR, INVALID MAP
	- map is rectangular (all lines same length)? OK
	- map enclosed in walls (first, last lines & places all = 1)? OK
	- only one exit ('E')? OK
	- only one start pos ('P')? OK
	- at least one collectible ('C')? OK
	- is there a possible route to all collectibles & the exit? OK
*/

//Store map's width & height. Check if path leads to a map, all line lengths 
//are equal & map is big enough to have P, C & E. If not, post error & exit
void	measure_map(t_map *map)
{
	int		fd;
	char	*line_read;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		error_msg("No map found");
	line_read = get_next_line(fd);
	map->width = ft_linelen(line_read);
	while (line_read)
	{
		if (ft_linelen(line_read) != map->width)
		{
			free(line_read);
			error_msg("Map not rectangular");
		}
		map->height++;
		free(line_read);
		line_read = get_next_line(fd);
	}
	close(fd);
	if (map->width == 0)
		error_msg("Map is empty");
	else if (map->width + map->height < 8)
		error_msg("Map is too small");
}

//allocate mem for grid & check, then fill w/ chars read from map file
//What happens if I don't include checks for failed allocation?
//must figure out when to free mem allocated to grid
void	fill_grid(t_map *map)
{
	size_t	i;
	int		fd;

	i = 0;
	fd = open(map->path, O_RDONLY);
	//dynamically allocate memory for (map height) ptrs to char (array of ptrs)
	map->grid = malloc(sizeof(char*) * map->height);
	map->check = malloc(sizeof(char*) * map->height);
	//do the following for y rows
	while (i < map->height)
	{
		//allocate memory for each string in matrix
		map->grid[i] = get_next_line(fd);
		//copy current line in **grid into **check
		map->check[i] = ft_strdup(map->grid[i]);
		i++;
	}
	close(fd);
}

//check if outer values = 1
void	check_walls(t_map *map)
{
	t_point	p;

	p.x = 0;
	p.y = 0;
	while (p.y < map->height)
	{
		while (p.x < map->width)
		{
			if ((p.y == 0 || p.y == map->height - 1 || p.x == 0
					|| p.x == map->width - 1) && map->grid[p.y][p.x] != '1')
				error_free_maps(map, "Map not enclosed by walls");
			if (map->grid[p.y][p.x] != '0' && map->grid[p.y][p.x] != '1'
					&& map->grid[p.y][p.x] != 'P' && map->grid[p.y][p.x] != 'E'
					&& map->grid[p.y][p.x] != 'C')
				error_free_maps(map, "Map contains invalid element");
			if (map->grid[p.y][p.x] == 'P')
			{
				map->player_pos.x = p.x;
				map->player_pos.y = p.y;
			}
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
}

//check for 1 P & E, at least 1 C. Return # of C
void	check_grid(t_map *map)
{
	size_t	i;
	size_t	j;
	int		cpe_ct;

	i = 0;
	j = 0;
	cpe_ct = 0;
	while (i < map->height)
	{
		while (j < map->width)
		{
			if (map->grid[i][j] == 'P')
				cpe_ct += 10;
			else if (map->grid[i][j] == 'E')
				cpe_ct += 1;
			else if (map->grid[i][j] == 'C')
				cpe_ct += 100;
			j++;
		}
		j = 0;
		i++;
	}
	if ((cpe_ct - 11) % 100 != 0 || cpe_ct < 111)
		error_free_maps(map, "Map must have 1 exit, 1 start pos & at least 1 collectible");
	map->collectibles = cpe_ct / 100;
}

//fill grid matrix from .ber file
void	parse_map(t_map *map)
{
	//define below vars as 0; might make sense to do elsewhere
	//map->check_collect = 0;
	//map->exits = 0;
	measure_map(map);
	//allocate mem for grid matrix, read map file & record each char
	fill_grid(map);
	//check if outer values = 1, for 1 P & E, at least 1 C
	check_walls(map);
	check_grid(map);
	//check for a possible route to all Cs & E
	validate_path(map, map->player_pos.y, map->player_pos.x);
	//free mem allocated to check matrix used for validate_path
	free_check(map);
	if (map->exits != 1 || map->collectibles != map->check_collect)
		error_free_maps(map, "No valid path");
	map->collectibles = 0;
}

/*test main
int	main(int argc, char **argv)
{
	t_map	map;
	size_t	i;

	if (argc != 2)
		return(1);
	i = 0;
	map.path = argv[1];
	map.check_collect = 0;
	map.exits = 0;
	measure_map(&map);
	//allocate mem for grid matrix, read map file & record each char
	fill_grid(&map);
	check_walls(&map);
	check_grid(&map);
	//print matrix area row by row (# of rows given by y of the size
	//struct, starting w/ 0 & ending w/ y - 1
	while (i < map.height)
	{
		printf("%s\n", map.grid[i]);
		i++;
	}
	printf("# of collectibles: %i\n", map.collectibles);
	printf("start pos: %zu, %zu\n", map.player_pos.x, map.player_pos.y);
	i = 0;
	validate_path(&map, map.start_pos.y, map.start_pos.x);
	printf("# of check_collect: %i\n", map.check_collect);
	printf("# of exits: %i\n", map.exits);
	while (i < map.height)
	{
		printf("%s\n", map.check[i]);
		i++;
	}
	free_check(&map);
	if (map.exits != 1 || map.collectibles != map.check_collect)
		error_msg("No valid path");
	return (0);
}*/