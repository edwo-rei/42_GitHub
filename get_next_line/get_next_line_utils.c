/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:50:25 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/06/11 19:21:41 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//to be able to use ft_strjoin
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//needed to use ft_substr
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = malloc(count * size);
	if (mem == 0)
		return (NULL);
	while (i < count * size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

//needed to initialize (& allocate memory for) chars_read when empty in fill_line func
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

//to join buffer just read w/ previous chars read w/o a \n
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

//to find \n in the buffer that's just been read
char	*ft_strchr(const char *s, int c)
{
	char	*ch;
	char	letter;

	ch = (char *)s;
	letter = (char)c;//allows values beyond 127 to be used, only lower byte matters, like strchr
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

	//return NULL if there is nothing in s
	if (s == 0)
		return (0);
	//if start is beyond s, return a valid empty string (""), but not NULL, which typically signals an allocation failure
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	//if len exceeds last char in s, cut len down to max possible to avoid undefined behavior after NULL char is reached
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	//initializes pointer to sub by allocating memory for it
	sub = malloc(len + 1);
	if (sub == 0)
		return (0);//signals failure to allocate memory
	i = 0;
	//assign chars indicated by start & len to sub
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	//append NULL char to end of substring
	sub[i] = 0;
	return (sub);
}
