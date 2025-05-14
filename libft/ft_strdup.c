/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:45:09 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/09 11:37:14 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc((ft_strlen(str) + 1) * sizeof(char));//+1 bc '\0' not counted by ft_strlen
	if (dup == 0)
		return (0);//0 is ASCII code for NULL
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';//append '\0' at end of new string
	return (dup);
}
/*
int	main(void)
{
	char	test[] = "This is a test string.";
	char	*dup;
	char	weird[] = "	kjie$ 879 !? öé";
	char	empty[] = "";

	dup = strdup(test);
	printf("strdup test: %s\n", dup);
	free(dup);
	dup = ft_strdup(test);
	printf("ft_strdup test: %s\n", dup);
	free(dup);
	dup = strdup(weird);
	printf("strdup weird: %s\n", dup);
	free(dup);
	dup = ft_strdup(weird);
	printf("ft_strdup weird: %s\n", dup);
	free(dup);
	dup = strdup(empty);
	printf("strdup empty: %s\n", dup);
	free(dup);
	dup = ft_strdup(empty);
	printf("ft_strdup empty: %s\n", dup);
	free(dup);
}*/
