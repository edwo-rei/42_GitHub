/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:07:14 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/09 12:38:10 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	//allocate enough memory for s1, s2 & '\0' to s3
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	//if allocation fails, return NULL
	if (!s3)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		j++;
		i++;
	}
	s3[i] = 0;
	return (s3);
}
/*
int	main(void)
{
	char	s1[] = "This is ";
	char	s2[] = "a test string.";
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	printf("%s\n", s3);
	free(s3);
}*/
