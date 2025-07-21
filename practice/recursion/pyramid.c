#include <stdio.h>
#include <stdlib.h>

void	draw(int n)
{
	int	i;

	i = 0;
	//if nothing to draw, don't draw, return (base case)
	if (n < 1)
		return;
	//print pyramid of height n - 1
	draw (n - 1);
	//print 1 more row
	while (i < n)
	{
		printf("#");
		i++;
	}
	printf("\n");
}

int	main(int argc, char ** argv)
{
	if (argc == 2)
		draw(atoi(argv[1]));
}
