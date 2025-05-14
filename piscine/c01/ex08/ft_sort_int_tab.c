/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:57:47 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/10 20:20:54 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_sorted(char *str)//function returns 1 if any char's value is less than the previous char
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] < str[i - 1])
			return (1);
		i++;
	}
	return (0);//will return 0 when every char is greater than the one that preceded it
}

void	bubblesort(char *string)
{
	int	j;
	char	swap;

	while (ft_is_sorted(string))//function will keep returning 1 until every char is greater than prior char, while loop will keep running until then
	{
		j = 1;
		while (string[j])
		{
			if (string[j - 1] > string[j])//if a char is greater than one before, swap them
			{
				swap = string[j - 1];
				string[j - 1] = string[j];
				string[j] = swap;
			}
			j++;
		}
	}
}

int	main(void)
{
	char	letters[] = "94827351";

	bubblesort(letters);
	printf("%s", letters);
}
