#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	print_bits(unsigned char octet)
{
	int		i;
	unsigned char	bit;

	//initialize i to 8 to count down backwards for the 8 places
	i = 8;
	bit = 0;
	//i's value decreases by 1 before entering {}, so i = 7 on 1st 
	//iteration
	while (i--)
	{
		//>> shift the bits right i places. The & bitwise operator
		//has a result of 1 only if there are 1s in both
		//corresponding places in the bit representations of each #
		//1 bitwise is 0000 0001. Adding 48 converts the resuling
		//0 or 1 to its ASCII representation
		bit = (octet >> i & 1) + 48;
		write(1, &bit, 1);
	}
}

int	main(int argc, char **argv)
{
	unsigned char	octet;

	if (argc == 2)
	{
		octet = (unsigned char)atoi(argv[1]);
		print_bits(octet);
	}
	write(1, "\n", 1);
}

