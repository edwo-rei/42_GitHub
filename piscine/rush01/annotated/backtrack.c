/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:36:35 by mapascua          #+#    #+#             */
/*   Updated: 2025/03/31 16:39:11 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	validate_map(int **map, int **views);//import prototype of function from validations.c that makes sure # of bldgs visible from each pov matched the # in that pov position

void	print_map(int **map)
{
	int		i;
	int		j;
	char	nb;

	i = 0;//row counter
	nb = '0';//height of bldg in current pos
	while (i < 4)//while loop for each row
	{
		j = 0;//column counter
		while (j < 4)//while loop for each column within a row
		{
			nb = map[i][j] + '0';//add value from map matrix to ascii code for the digit 0 and make it the value of the nb variable (bldg height)
			write(1, &nb, 1);//write the value of bldg height
			if (j < 3)//add a space if not in last pos
				write(1, " ", 1);
			j++;//increase column pos counter by 1
		}
		write(1, "\n", 1);//move to a new line
		i++;//increase row counter by 1
	}
}

int	is_in_row(int *row, int n)//function that makes sure same value doesn't appear twice in the same row
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (row[i] == n)
			return (-1);//return error  if value for a given pos matches number gives as parameter when function is executed
		i++;
	}
	return (0);
}

int	is_in_col(int **map, int n, int col)//function that makes sure the same value doesn't appear twice in same column
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map[i][col] == n)
			return (-1);
		i++;
	}
	return (0);
}

int	backtrack(int **map, int **views, int row, int col)//function that solves the skyscraper puzzle
{
	int	n;

	n = 1;//bldg height value
	if (row == 3 && col > 3)//if the last position in map has been reached
		return (validate_map(map, views));//return the result of the validation of  the entire map. If 0, function concludes
	if (col > 3)//if last column has been reached, move to next row and reset column counter
	{
		row++;
		col = 0;
	}
	if (map[row][col] != 0)//if the position value in map is not equal to 0
		return (backtrack(map, views, row, col + 1));// move forward to next column
	while (n <= 4)
	{
		if ((!is_in_row(map[row], n)) && (!is_in_col(map, n, col)))//if this value hasn't previously appeard in this row & column (otherwise, n will increase 1 & funtion will try again)
		{
			map[row][col] = n;//assign this building height
			if (backtrack(map, views, row, col + 1) == 0)//then check if bldg height assigned in next column is valid, and then the next, and so on recursively until the last value in map
				return (0);//if all are valid, return 0 (valid/true) and stop recursion
			map[row][col] = 0;//otherwise, reset the value for this pos in map to 0, while loop concludes
		}
		n++;//increase bldg height variable by 1 & try the process again
	}
	return (-1);//if none of that works, return error code indicating no possible solution
}
