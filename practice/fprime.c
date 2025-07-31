#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	nb;
	int	div;

	if (argc == 2)
	{
		nb = atoi(argv[1]);
		//if input is 1, ex. says must output 1, even if not prime
		if (nb == 1)
			printf("1");
		else
		{
			div = 2;
			//run this loop dividing nb until it is 1
			while (nb > 1)
			{
				//check if div is a divisor of nb
				if (nb % div == 0)
				{
					//if so, print it
					printf("%i", div);
					//divide nb by it
					nb /= div;
					//& if nb is still not 1, print *
					if (nb > 1)
						printf("*");
				}
				//if not a divisor, increase by 1 & repeat
				else
					div++;
			}
		}
	}
	printf("\n");
}
