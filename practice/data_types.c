#include <stdio.h>
#include <limits.h>//must be used in order to use INT_MAX/MIN
#include <float.h>//must be used for FLT_MAX/MIN

int	main(void)
{
	printf("%i\n", SHRT_MAX);
	printf("%i\n", SHRT_MIN);
	printf("%f\n", FLT_MAX);
	printf("%f\n", FLT_MIN);
}
