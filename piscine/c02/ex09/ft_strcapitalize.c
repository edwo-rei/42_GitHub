/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:27:22 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/02 10:57:21 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
*/
char	*ft_strcapitalize(char *str)
{
	int	i;

	if ('a' <= *str && *str <= 'z')//if first char is a lowercase letter, capitalize it
		*str -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if ((('A' < str[i] && str[i] < 'Z') || ('a' < str[i] && str[i] < 'z'))
			&& ((str[i - 1] < '0' || ('9' < str[i -1] && str[i - 1] < 'A')
					|| ('Z' < str[i -1] && str[i - 1] < 'a')
					|| str[i - 1] > 'z')))//if a letter not preceded by an alphanumeric char
		{
			if ('a' <= str[i] && str[i] <= 'z')//and if it's lowercase, make it uppercase
				str[i] -= 32;
		}
		else if ('A' <= str[i] && str[i] <= 'Z')//if preceded by alphanumeric char & uppercase, make lowercase
			str[i] += 32;
		i++;//increase counter variable to move to next char in array
	}
	return (str);
}
/*
int	main(void)
{
	char 	letters[] = "piscine";
	char 	phrase[] = "what is this place?";
	char 	mix[] = "PiscIne42";
	char	empty[] = "";

	ft_strcapitalize(letters);
	printf("%s\n", letters);
	ft_strcapitalize(phrase);
	printf("%s\n", phrase);
	ft_strcapitalize(mix);
	printf("%s\n", mix);
	ft_strcapitalize(empty);
	printf("%s\n", empty);
}*/
