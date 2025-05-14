/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:50:36 by mapascua          #+#    #+#             */
/*   Updated: 2025/03/31 10:59:02 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	validate_row_left(int *map, int view_left)//start validation process from left-side views
{
	int	i;
	int	view;
	int	max_height;

	i = 0;//place counter
	view = 1;//# of bldgs visible from given pov
	max_height = map[0];//height of bldg at current position
	while (i < 3)//while loop that runs check process from first 3 positions in a view line
	{
		if (max_height < map[i + 1])//if height of bldg in current pos is less thanheight of building in next pos (to the right)
		{
			view++;//increase # of bldgs visible from pov by 1
			max_height = map[i + 1];//redefine max_height variable to match height of bldg in next pos
		}
		i++;//move to next pos in row
	}
	if (view != view_left)//if view variable (# of bldgs visible from pov) is not equal to the integer for that position in left-side views, return error
		return (-1);
	return (0);//otherwise, return zero (true)
}

int	validate_row_right(int *map, int view_right)//repeat process from right-side views
{
	int	i;
	int	view;
	int	max_height;

	i = 3;//start in place 3 (4th pos) and decrease
	view = 1;
	max_height = map[3];
	while (i > 0)//until you reach place 0 (1st pos)
	{
		if (max_height < map[i - 1])//if height of bldg in current pos is less than bldg to its left
		{
			view++;//increase # of bldgs visible from pov
			max_height = map[i - 1];//redefine height var to match bldg in next pos
		}
		i--;
	}
	if (view != view_right)
		return (-1);
	return (0);
}

int	validate_col_up(int **map, int col, int view_up)//repeat process from top side; because row will change, it's necessary to use double pointer (to refer to the whole matrix)
{
	int	i;
	int	view;
	int	max_height;

	i = 0;
	view = 1;
	max_height = map[0][col];//column value is added and remains constant
	while (i < 3)
	{
		if (max_height < map[i + 1][col])//height of bldg in current pos < height of blgd one row down
		{
			view++;
			max_height = map[i + 1][col];//reset height to bldg next row down
		}
		i++;//move down a row
	}
	if (view != view_up)
		return (-1);
	return (0);
}

int	validate_col_down(int **map, int col, int view_down)//from bottom row of views
{
	int	i;
	int	view;
	int	max_height;

	i = 3;
	view = 1;
	max_height = map[3][col];
	while (i > 0)
	{
		if (max_height < map[i - 1][col])
		{
			view++;
			max_height = map[i - 1][col];
		}
		i--;//decrease i to move up rows
	}
	if (view != view_down)
		return (-1);
	return (0);
}

int	validate_map(int **map, int **views)//implement each of the validate pov functions for each row & column from each side using parameters of map and views matrices
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < 4)//while loop runs validate row function for each row from both sides
	{
		if (validate_row_left(map[row], views[2][row]) == -1)//for each place in the row in pos 2 (3rd pos) of the views matrix
			return (-1);
		if (validate_row_right(map[row], views[3][row]) == -1)//for each place in the row in pos 3 (4th pos) of views matrix
			return (-1);
		row++;//move to next row
	}
	while (col < 4)//while loop runs validate column function for each column from top & bottom
	{
		if (validate_col_up(map, col, views[0][col]) == -1)//row 0 (1st row) in views matrix
			return (-1);
		if (validate_col_down(map, col, views[1][col]) == -1)//row 1 (2nd row)
			return (-1);
		col++;
	}
	return (0);//if all rows & columns are validated, return 0
}
