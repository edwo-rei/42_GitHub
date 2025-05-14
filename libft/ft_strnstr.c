/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:41:56 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/07 12:42:49 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*pbig;
	char	*plittle;
	size_t	i;

	pbig = (char *)big;
	plittle = (char *)little;
	if (*plittle == '\0')
		return (pbig);
	while (len && *pbig)//to make sure that chars after '\0' aren't searched
	{
		if (*pbig == *plittle)
		{
			i = 0;
			while ((len > i) && (pbig[i] == plittle[i]))
			{
				i++;
				if (plittle[i] == '\0')
					return (pbig);
			}
		}
		pbig++;
		len--;
	}
	return (0);
}
/*
int	main(void)
{
	char	large[] = "abcdefgh";
	char	small[] = "def";
	char	absent[] = "thread";
	char	empty[] = "";
	size_t	n;

	n = sizeof(large);
	printf("%p\n", strnstr(large, small, n));
	printf("%s\n", strnstr(large, small, n));
	printf("%p\n", ft_strnstr(large, small, n));
	printf("%s\n", ft_strnstr(large, small, n));
	printf("%p\n", strnstr(large, absent, n));
	printf("%s\n", strnstr(large, absent, n));
	printf("%p\n", ft_strnstr(large, absent, n));
	printf("%s\n", ft_strnstr(large, absent, n));
	printf("%p\n", strnstr(large, empty, n));
	printf("%s\n", strnstr(large, empty, n));
	printf("%p\n", ft_strnstr(large, empty, n));
	printf("%s\n", ft_strnstr(large, empty, n));
	printf("%p\n", strnstr(absent, absent, sizeof(absent)));
	printf("%s\n", strnstr(absent, absent, sizeof(absent)));
	printf("%p\n", ft_strnstr(absent, absent, sizeof(absent)));
	printf("%s\n", ft_strnstr(absent, absent, sizeof(absent)));
	printf("%p\n", strnstr("", "xx", 4294967295));
	printf("%p\n", ft_strnstr("", "xx", 4294967295));
}*/
