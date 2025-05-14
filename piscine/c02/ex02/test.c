#include <stdio.h>

int	main(void)
{
	char	a;//[] = "Test";
	char	b;//[] = "0123456789";
	char	c;//[] = "p15c1ne";

	a = 'h';
	b = '7';
	c = '!';

	if ((a > 64 && a < 91) || (a > 96 && a < 123))
		printf("letter\n");
	else
		printf("not a letter\n");

	if ((b > 64 && b < 91) || (b > 96 && b < 123))
                printf("letter\n");
        else
                printf("not a letter\n");

	if (!(c > 64 && c < 91) || (c > 96 && c < 123))
                printf("not a letter\n");
}
