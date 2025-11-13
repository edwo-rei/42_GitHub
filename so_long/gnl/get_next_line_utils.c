/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:50:25 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/03 19:18:10 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//to be able to use ft_strjoin. Changed name so it woulnd't conflict when
//compiled w/ libft
size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//needed to initialize (& allocate memory for) chars_read when empty in 
//fill_line func
char	*my_strdup(const char *str)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc((my_strlen(str) + 1) * sizeof(char));
	if (dup == 0)
		return (0);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

//to join buffer just read w/ previous chars read w/o a \n
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = malloc(my_strlen(s1) + my_strlen(s2) + 1);
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

//to find \n in the buffer that's just been read
char	*ft_strchr(const char *s, int c)
{
	char	*ch;
	char	letter;

	ch = (char *)s;
	letter = (char)c;
	while (*ch)
	{
		if (*ch == letter)
			return (ch);
		ch++;
	}
	if (*ch == letter)
		return (ch);
	return (NULL);
}

//to copy everything after \n in buffer to static var
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == 0)
		return (0);
	if (start >= my_strlen(s))
		return (my_strdup(""));
	if (len > my_strlen(s + start))
		len = my_strlen(s + start);
	sub = malloc(len + 1);
	if (sub == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
