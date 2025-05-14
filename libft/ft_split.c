/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:31:42 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/09 20:16:09 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*- "const char *s" means value @ address is constant, not address itself. 
  - The function counts a word when the "word" variable is at 0, then sets 
  "word" to 1 until the delimiter is encountered - which sets it back to 0, 
  allowing the next word to be counted*/
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

/*necessary to know how long word is to write malloc, so start by counting
  length of 1st word, allocate memory, then copy chars to ptr using index*/
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

/*If a malloc in copy_word fails on not the 1st allocation, it's necessary to
 free the previously allocated strings individually - then the array that holds
 them can be freed. It's possible to return NULL, also, but would have to make
 return value a ptr*/
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

/*function counts words in string, allocates mem for ptr for each word, then
  fills each string in the array (or row in matrix) using copy_word. Location
  in s is maintained by jumping forward # of chars of string just created*/
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
/*
int	main(void)
{
	char	s[] = "This is a test string.";
	char	c;
	char	**matrix;
	int	i;

	c = ' ';
	i = 0;
	matrix = ft_split(s, c);
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		free(matrix[i]);
		i++;
	}
	free(matrix);
}*/
