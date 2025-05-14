/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:52:37 by mapascua          #+#    #+#             */
/*   Updated: 2025/03/30 20:22:42 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill4_aux(int **map, int view_row)
{
	if (view_row == 2)
	{
		map[view_row][0] = 1;
		map[view_row][1] = 2;
		map[view_row][2] = 3;
		map[view_row][3] = 4;
	}
	if (view_row == 3)
	{
		map[view_row][0] = 4;
		map[view_row][1] = 3;
		map[view_row][2] = 2;
		map[view_row][3] = 1;
	}
}

void	fill4(int **map, int view_row, int view_col)
{
	if (view_row == 0)
	{
		map[0][view_col] = 1;
		map[1][view_col] = 2;
		map[2][view_col] = 3;
		map[3][view_col] = 4;
	}
	if (view_row == 1)
	{
		map[0][view_col] = 4;
		map[1][view_col] = 3;
		map[2][view_col] = 2;
		map[3][view_col] = 1;
	}
	if (view_row > 1)
		fill4_aux(map, view_row);
}

void	fill1(int **map, int view_row, int view_col)
{
	if (view_row == 0)
		map[0][view_col] = 4;
	if (view_row == 1)
		map[3][view_col] = 4;
	if (view_row == 2)
		map[view_row][0] = 4;
	if (view_row == 3)
		map[view_row][3] = 4;
}

/*
** fill3_2 takes as input the row with the 3 across from the 2, never in reverse
*/

void	fill3_2(int **map, int view_row, int view_col)
{
	if (view_row == 0)
		map[2][view_col] = 4;
	if (view_row == 1)
		map[1][view_col] = 4;
	if (view_row == 2)
		map[view_row][2] = 4;
	if (view_row == 3)
		map[view_row][1] = 4;
}

/*
** fill2_1 takes as input the row with the 2 across from the 1, never in reverse
*/

void	fill2_1(int **map, int view_row, int view_col)
{
	if (view_row == 0)
		map[0][view_col] = 3;
	if (view_row == 1)
		map[3][view_col] = 3;
	if (view_row == 2)
		map[view_row][0] = 3;
	if (view_row == 3)
		map[view_row][3] = 3;
}
