/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:27:22 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/01 19:50:31 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	word;

	word = 0;
	while (*str)
	{
		if (!(('0' < *str && *str < '9') || ('A' < *str && *str < 'Z'
			) || ('a' < *str && *str < 'z')))
		{
			str++;
			write(1, "a", 1);
			write(1, "\n", 1);
		}
		else if ('a' < *str && *str < 'z')
		{
			*str -= 32;
			str++;
			write(1, "b", 1);
			write(1, "\n", 1);
		}
		while (word < 1)
		{
			if ('A' < *str && *str < 'Z')
			{
				*str += 32;
				str++;
				write(1, "c", 1);
			}
			else if (('0' < *str && *str < '9') || ('a' < *str && *str < 'z'))
			{
				str++;
			}
			word++;
		}
	}
	return (str);
}

int	main(void)
{
	char 	letters[] = "piscine";
	char 	phrase[] = "what is the number";
	char 	mix[] = "PiscIne42";
	char	empty[] = "";

	ft_strcapitalize(letters);
	printf("%s\n", letters);
	/*ft_strcapitalize(phrase);
	printf("%s\n", phrase);
	ft_strcapitalize(mix);
	printf("%s\n", mix);
	ft_strcapitalize(empty);
	printf("%s\n", empty);*/
}
