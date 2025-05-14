#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		printf("Greetings, %s", argv[1]);
		printf(" %s\n", argv[2]);
	}
	return (0);
}
