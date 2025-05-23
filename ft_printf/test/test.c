#include "ft_printf.h"

int	main(void)
{
	char	*str = "John Jacob Jingleheimer Schmidt";
	int	result;
	int	i = 42;

	result = ft_printf("Hello, %s, your alias is %i and your location is %p\n", str, i, str);
	printf("ft_printf return value: %i\n", result);
	result = printf("Hello, %s, your alias is %i and your location is %p\n", str, i, str);
	printf("printf return value: %i\n", result);
}
