/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrios-ag <josemanueljbk99@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:43:46 by mapascua          #+#    #+#             */
/*   Updated: 2025/03/31 18:03:09 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	free_maps(int **map);//call prototypes of needed functions
int		ft_error(int mem, int **map, int **views);
int		ft_strlen(char *str);
int		validate_input(char *str);
int		get_safe_cells(int **map, int **views);
int		backtrack(int **map, int **views, int row, int col);
int		print_map(int **map);

void	init_map(int **tab)//create map full of 0s
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < 4)
	{
		while (col < 4)
		{
			tab[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	**get_arg_values_aux(char *arg, int **views)
{
	int	pos;
	int	i;
	int	j;

	pos = 0;
	i = 0;
	j = 0;
	while (arg[pos])
	{
		if (pos % 2 == 0)//from the positions in the input string that contain number characters
		{
			views[j][i] = arg[pos] - '0';//conversion from input characters to ascii values by subtracting ascii value of '0' (48) and defining them to positions in views matrix
			i++;//move to next pos
		}
		if (i > 3)
		{
			j++;
			i = 0;
		}
		pos++;
	}
	return (views);//returns the views matrix with integers
}

int	**get_arg_values(char *arg)
{
	int	**views;
	int	i;

	views = malloc(sizeof(int *) * 4);//allocate memory - # of bytes for int pointer * 4
	i = 0;
	while (i < 4)
	{
		views[i] = malloc(sizeof(int) * 4);//allocate memory for every side of views
		i++;
	}
	return (get_arg_values_aux(arg, views));
}

int	main(int argc, char **argv)
{
	int	map[4][4];//solution values matrix
	int	**views;//pov from each pos on each side matrix
	int	i;//counter

	map = malloc(sizeof(int *) * 4);//allocates memory needed for an int * 4
	i = 0;
	while (i < 4)//does it for 4 rows
	{
		map[i] = malloc(sizeof(int) * 4);//using malloc allows us to reserve RAM for our calculations and refer to it using pointers, and then changing the values in this memory. If we didn't use malloc, trying many iterations would occupy lots of RAM - potentially too much - and possibly cause the program to crash
		i++;
	}
	if (argc != 2)//argument count should be 2, name of program & string of characters
		return (ft_error(0, NULL, NULL));
	if (validate_input(argv[1]) == -1)//if string is not valid, return error
		return (ft_error(0, NULL, NULL));
	init_map(map);//create map full of 0s
	views = get_arg_values(argv[1]);//creates views matrix based on input string
	if (get_safe_cells(map, views) == -1)
		return (ft_error(2, map, views));//return Error if values are not solvable
	if (backtrack(map, views, 0, 0) == -1)//run solving function
		return (ft_error(2, map, views));//return error if solving function can't find solution
	print_map(map);//print the solution map
	free_maps(map);//free up memory allocated for map matrix
	free_maps(views);//free up memory used for view matrix
	return (0);
}
