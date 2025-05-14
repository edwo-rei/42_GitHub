/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:29:14 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/04 12:18:42 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			while (str[i] == to_find[i])
			{
				i++;
				if (to_find[i] == '\0')
					return (str);
			}
			i = 0;
		}
		str++;
	}
	return (0);
}

int	main(void)
{
	char	str[] = "Like looking for a needle in a haystack";
	char	to_find[] = "needle";
	char	absent[] = "thread";
	char	empty[] = "";

	printf("%s\n", strstr(str, to_find));
	printf("%s\n", strstr(str, absent));
	printf("%s\n", strstr(str, empty));
	printf("%s\n", ft_strstr(str, to_find));
	printf("%s\n", ft_strstr(str, absent));
	printf("%s\n", ft_strstr(str, empty));
	return (0);
}
