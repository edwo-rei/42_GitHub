/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:41:56 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/02 19:16:26 by edwo-rei         ###   ########.fr       */
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
	if (*pbig == '\0')
		return (0);
	while (len--)
	{
		if (*pbig++ == *plittle)
		{
			i = 0;
			while ((len + 1 > i) && (pbig[i - 1] == plittle[i]))
			{
				i++;
				if (plittle[i] == '\0')
					return (pbig - 1);
			}
		}
	}
	return (0);
}

int	main(void)
{
	char	large[] = "abcdefgh";
	char	small[] = "abc";
	char	absent[] = "thread";
	char	empty[] = "";
	size_t	n;

	n = 3;
	printf("%p\n", strnstr(large, small, n));
	printf("%s\n", strnstr(large, small, n));
	printf("%p\n", ft_strnstr(large, small, n));
	printf("%s\n", ft_strnstr(large, small, n));
	printf("%p\n", strnstr(absent, absent, n));
	printf("%s\n", strnstr(absent, absent, n));
	printf("%p\n", ft_strnstr(absent, absent, n));
	printf("%s\n", ft_strnstr(absent, absent, n));
	printf("%p\n", strnstr(large, empty, n));
	printf("%s\n", strnstr(large, empty, n));
	printf("%p\n", ft_strnstr(large, empty, n));
	printf("%s\n", ft_strnstr(large, empty, n));
	printf("%p\n", strnstr(empty, absent, n));
	printf("%p\n", ft_strnstr(empty, absent, n));
}
