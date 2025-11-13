/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:31:42 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/09 19:59:24 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//"const char *s" means value @ address is constant, not address itself
static int	count_words(const char *s, char c)
{
	int	wc;
	int	word;

	wc = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && word == 0)
		{
			word++;
			wc++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (wc);
}

//necessary to know how long word is to write malloc
static char	*copy_word(const char *s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = *s;
		i++;
		s++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_strings(char **matrix, int full_strings)
{
	int	i;

	i = 0;
	while (i < full_strings)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**ft_split(const char *s, char c)
{
	char	**matrix;
	int		i;
	int		wc;

	wc = count_words(s, c);
	matrix = malloc((wc + 1) * sizeof(char *));
	if (!matrix)
		return (0);
	i = 0;
	while (*s && i < wc)
	{
		while (*s == c)
			s++;
		matrix[i] = copy_word(s, c);
		if (!matrix[i])
		{
			free_strings(matrix, i);
			return (0);
		}
		s += ft_strlen(matrix[i]);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
