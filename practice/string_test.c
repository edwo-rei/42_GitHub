#include <stdio.h>

int	main(void)
{
	char	string[] = "test";
	int	i;

	i = 0;
	while (i <5)
	{
		printf("%c %i\n", *(string + i), *(string + i));
		i++;
	}
}

