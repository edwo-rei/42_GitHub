/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:49:46 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/04 12:54:40 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
*/
int	ft_strlen(char *str)
{
	int	i;//define a counter variable

	i = 0;//intitialize it at 0
	while (str[i])//creat a while loop that will last as long as their are chars in the string
	{
		i++;//increase the counter by 1 for every char
	}
	return (i);//return the value of the counter
}
/*
int	main(void)
{
	char* string;

	string = "piscine";
	printf("%i", (ft_strlen(string)));
}*/
