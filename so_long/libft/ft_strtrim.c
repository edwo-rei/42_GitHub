/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:43:00 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/09 20:04:09 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Return a count of the # of chars to trim from front of s1
static int	front_trim(const char *s1, const char *set)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < ft_strlen(set))
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

//Return a count of the # of chars to trim from the end of s1
static int	back_trim(const char *s1, const char *set)
{
	int		i;
	int		n;
	size_t	j;

	i = ft_strlen(s1) - 1;
	n = 0;
	j = 0;
	while (j < ft_strlen(set))
	{
		if (s1[i] == set[j])
		{
			i--;
			n++;
			j = 0;
		}
		else
			j++;
	}
	return (n);
}

//Return a ptr to a trimmed string w/o the chars contained in set
char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trimmed;
	int		i;
	int		ft;
	int		len;

	ft = front_trim(s1, set);
	len = ft_strlen(s1) - ft - back_trim(s1, set);
	i = 0;
	if (len < 1)
		return (ft_calloc(1, 1));
	trimmed = malloc(len + 1);
	if (!trimmed)
		return (0);
	while (i < len)
	{
		trimmed[i] = s1[i + ft];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
