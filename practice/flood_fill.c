/*#include <stdlib.h>
#include <stdio.h>
*/
typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

//recursive function to flood fill an area of a 2D char array
void	fill(char **tab, t_point size, t_point cur, char target)
{
	//base condition: check if current row & column are out of bounds
	if (cur.y < 0 || cur.x < 0 || cur.y >= size.y || cur.x >= size.x 
			|| tab[cur.y][cur.x] != target)
		return;
	//mark current cell as filled
	tab[cur.y][cur.x] = 'F';
	//recursively fill cells above, below, left & right
	//why (t_point) - casting?
	fill(tab, size, (t_point){cur.x - 1, cur.y}, target);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, target);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, target);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, target);
}

void	flood_fill(char	**tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
/*
char	**make_area(char **zone, t_point size)
{
	int	i;
	int	j;
	char	**new;

	i = 0;
	j = 0;
	//dynamically allocate memory for size.y ptrs to char (a matrix)
	new = malloc(sizeof(char*) * size.y);
	if (!new)
		return (NULL);
	//do the following for y rows
	while (i < size.y)
	{
		//allocate memory for each string in matrix
		new[i] = malloc (size.x + 1);
		if (!new[i])
			return (NULL);//(should free prev alloc arrays, but...)
		//do the following for x columns
		while (j < size.x)
		{
			//populate each spot in matrix w/ corresponding
			//value in the matrix received as parameter
			new[i][j] = zone[i][j];
			j++;
		}
		//finish each array w/ NULL char
		new[i][size.x] = 0;
		j = 0;
		i++;
	}
	return (new);
}

int	main(void)
{
	int	i;
	//set x of t_point struct to 8, y to 5
	t_point	size = {8, 5};
	//populate matrix zone w/ following 1s & 0s
	char	*zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	i = 0;
	//populate the matrix area so it matches matrix zone
	char	**area = make_area(zone, size);
	//print matrix area row by row
	while (i < size.y)
	{
		printf("%s\n", area[i]);
		i++;
	}
	printf("\n");
	i = 0;
	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	while (i < size.y)
	{
		printf("%s\n", area[i]);
		i++;
	}
	return (0);
}*/
