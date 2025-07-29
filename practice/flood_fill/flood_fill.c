#include <stdlib.h>
#include <stdio.h>

//structure to hold length & width of matrix or starting coordinates
typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

//recursive function to flood fill an area of a 2D char array
void	fill(char **tab, t_point size, t_point cur, char target)
{
	//base condition: check if current row & column are out of bounds
	//(>= b/c 1st spot is 0, so last spot is size.x/y - 1)
	if (cur.y < 0 || cur.x < 0 || cur.y >= size.y || cur.x >= size.x 
			|| tab[cur.y][cur.x] != target)
		return;
	//mark current cell as filled
	tab[cur.y][cur.x] = 'F';
	//recursively fill cells above, below, left & right
	//why (t_point) - casting? b/c you can't just pass {cur.x, cur.y},
	//the compiler won't know exactly what it is. You have to tell it
	//explicitly by "casting" - although you're not really casting.
	//You're creating a temporary struct of type t_point w/ fields
	//x = cur.x & y = cur.y
	fill(tab, size, (t_point){cur.x - 1, cur.y}, target);//fill above
	fill(tab, size, (t_point){cur.x + 1, cur.y}, target);//fill below
	fill(tab, size, (t_point){cur.x, cur.y - 1}, target);//fill left
	fill(tab, size, (t_point){cur.x, cur.y + 1}, target);//fill right
}

//using as parameters given table/matrix, its size & a starting point,
//flood fill that table from that starting pt. Must use a diff func for
//recursion in order to change only row or column by 1 on subsequent
//iterations
void	flood_fill(char	**tab, t_point size, t_point begin)
{
	//replace whatever char happens to be at beginning coordinates
	//& all of that same char that are contiguous
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

char	**make_area(char **zone, t_point size)
{
	int	i;
	int	j;
	char	**new;

	i = 0;
	j = 0;
	//dynamically allocate memory for size.y ptrs to char (an array of
	//ptrs)
	new = malloc(sizeof(char*) * size.y);
	if (!new)
		return (NULL);
	//do the following for y rows
	while (i < size.y)
	{
		//allocate memory for each string in matrix
		new[i] = malloc (size.x + 1);
		if (!new[i])
			return (NULL);//(should free prev alloc arrays, but)
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
	//return the ptr to the array of arrays (matrix)
	return (new);
}

int	main(void)
{
	int	i;
	//set x of t_point struct to 8, y to 5
	t_point	size = {8, 5};
	//set the beginning point from which to flood fill later on
	t_point begin = {6, 0};
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
	//print matrix area row by row (# of rows given by y of the size
	//struct, starting w/ 0 & ending w/ y - 1
	while (i < size.y)
	{
		printf("%s\n", area[i]);
		i++;
	}
	//print a blank line to separate matrices & reset index
	printf("\n");
	i = 0;
	flood_fill(area, size, begin);
	//print the flood filled matrix
	while (i < size.y)
	{
		printf("%s\n", area[i]);
		i++;
	}
	return (0);
}
