#include <stdio.h>

int	main()
{
	int	i;
	int	j;
	char	matrix[2][4] = { {"142\0"}, {"368\0"} };

	i = 0;
	//j = 0;
	while (*matrix[i])
	{
		//while (j < 3)
		//{
			printf("%s\n", matrix[i]);
			//j++;
		//}
		//j = 0;
		i++;
	}
	return (0);
}
