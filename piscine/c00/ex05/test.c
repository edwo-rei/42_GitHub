#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int numbers[] = {1, 2, 3};
	printf("%d\n", *(&numbers[0]));

	char array[] = {'1', '2', '3'};
	printf("%p\n", &array);
	write(1, &array, 3);
	return (0);
}
