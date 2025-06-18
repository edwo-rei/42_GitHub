#include <unistd.h>

void	recursion_base10(int n)
{
	char	base[] = "0123456789";

	if (n >= 10)
		recursion_base10(n / 10);
	write(1, &base[n % 10], 1);
}

int	main(void)
{
	int	n;

	n = 15;
	recursion_base10(n);
}
