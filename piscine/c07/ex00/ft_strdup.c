/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:49:09 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/10 19:48:41 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)//takes a ptr/str as parameter & returns a ptr/str
{
	int	i;
	int	m;
	char	*copy;

	i = 0;
	m = 0;
	if (src == 0)//return 0 if input ptr is empty
		return (0);
	while (src[i])//count length of str and store in i
		i++;
	copy = malloc(i * sizeof(char));//allot dynamic memory to ptr copy equal to the size of a char (1 byte) times size of string. The counter i has taken the null char into account
	if (copy == 0)//if memory allocation fails, return 0
		return (0);
	while (src[m])//new counter variable to start from beginning of src
	{
		copy[m] = src[m];//copy char by char from src to copy
		m++;//increase count
	}
	copy[m] = '\0';//append null char to end of string
	return (copy);//return copy of src string in copy string
	//free(copy);
}

int	main(void)
{
	char *source = "I guess you got me on that one, Rick";
	char *duplicate = ft_strdup(source);

	printf("%s", duplicate);
	free(duplicate);//you need to free up memory you've used once function is done with it
	return (0);
}
