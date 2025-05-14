#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	s1[] = "abc";
	char	s2[] = "abc";
	char	s3[] = "abd";
	char	s4[] = "ABC";

	printf("%i\n", strcmp(s1, s2));
	printf("%i\n", strcmp(s1, s3));
	printf("%i\n", strcmp(s1, s4));
	return (0);
}
