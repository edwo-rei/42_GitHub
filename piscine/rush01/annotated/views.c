/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:30:28 by mapascua          #+#    #+#             */
/*   Updated: 2025/03/31 17:04:30 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill4(int **map, int view_row, int view_col);
void	fill1(int **map, int view_row, int view_col);
void	fill3_2(int **map, int view_row, int view_col);
void	fill2_1(int **map, int view_row, int view_col);

int	check_view_numbers(int *view)//check to make sure there's no 1 or 4 in a given view pos
{
	int	i;//counter
	int	is_4;//counts 4s
	int	is_1;//counts 1s

	i = 0;//initialize variables at 0
	is_4 = 0;
	is_1 = 0;
	if ((view[0] + view[1] + view[2] + view[3]) < 7
		|| (view[0] + view[1] + view[2] + view[3]) > 10)//check for solvable values in each side of views (7 > sum < 10)
		return (-1);//if not solvable, return error code
	while (i < 4)
	{
		if (view[i] == 1)
			is_1++;//count 1s
		if (view[i] == 4)
			is_4++;//count 4s
		i++;//move to next pos in views
	}
	if (is_1 > 1 || is_4 > 1)//if there is more than 1 or 4, not solvable, return -1
		return (-1);
	return (0);
}

int	validate_views(int **views)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		if (check_view_numbers(views[row]) == -1)//first check for more than one 1 or 4
			return (-1);
		if (row % 2 == 0)//if in top view or left view row
		{
			col = 0;
			while (col < 4)//check to make sure #s across from each other don't sum to less than 3 or more than 5 - both unsolvable cases
			{
				if ((views[row][col] + views[row + 1][col]) < 3 ||
				(views[row][col] + views[row + 1][col]) > 5)
					return (-1);//if so, return -1
				col++;//move to check in next pos
			}
		}
		row++;//move to check in next view side (held in rows in the matrix)
	}
	return (0);
}

void	get_safe_cells_aux(int **map, int **views, int row, int col)
{
	if (views[row][col] == 4)//fill 1 2 3 4 in front of view 4
		fill4(map, row, col);
	if (views[row][col] == 1)// fill 4 in front of view 1
		fill1(map, row, col);
	if (views[row][col] == 3)//if 3 & 2 across from each other, put 4 at 2nd space from 2
	{
		if (row % 2 == 0)
			if (views[row + 1][col] == 2)
				fill3_2(map, row, col);
		if (row % 2 == 1)
			if (views[row - 1][col] == 2)
				fill3_2(map, row, col);
	}
	if (views[row][col] == 2)//if 2 & 1 across from each other, put 3 in front of 2
	{
		if (row % 2 == 0)
			if (views[row + 1][col] == 1)
				fill2_1(map, row, col);
	}
}

int	get_safe_cells(int **map, int **views)//fill sure thing map values
{
	int	row;
	int	col;

	if (validate_views(views) == -1)
		return (-1);
	row = 0;
	col = 0;
	while (row < 4)
	{
		while (col < 4)
		{
			get_safe_cells_aux(map, views, row, col);
			col++;
		}
		row++;
	}
	return (0);
}
