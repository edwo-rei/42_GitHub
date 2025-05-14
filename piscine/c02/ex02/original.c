#include <stdio.h>

int    ft_str_is_alpha(char *str)
{
	int    notc_counter;

	notc_counter = 0;
	while (*str)
	{
		if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
			notc_counter++;
		str++;
	}
	if (notc_counter > 0)
		return(0);
	else
		return(1);
}

int    main(void)
{
	char     letters[] = "piscine";
	char     numbers[] = "0123456789";
	char     mix[] = "p15c1n9";
	char    empty[3] = "";

	printf("return value is %d\n", ft_str_is_alpha(letters));
	printf("return value is %d\n", ft_str_is_alpha(numbers));
	printf("return value is %d\n", ft_str_is_alpha(mix));
	printf("return value is %d\n", ft_str_is_alpha(empty));
}
