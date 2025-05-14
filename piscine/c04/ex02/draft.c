/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:07:03 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/06 13:45:17 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb)
{
	char	str[19];//print input as chars string
	char	reverse[19];//string for recording input int in reverse
	int	i;//counter for reverse string
	int	j;//counter for print string
	int	neg;//variable to record negative ints

	i = 0;
	j = 0;
	neg = 0;
	if (nb == 0)//if int is 0, 0 plus null char is assigned to str, then jump to write
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else//if not 0, convert to chars
		if (nb < 0)//in the case of negative #s
		{
			neg = 1;//set neg variable to 1
			nb = -nb;//make the input int positive
		}
		while (nb != 0)
		{
			reverse[i] = (nb % 10) + 48;//record remainder (smallest place) in reverse string
			nb = nb / 10;//remove that remainder once recorded
			i++;//increase counter to run operation until no remaining #s
		}
		if (neg > 0)//if it was a neg #
		{
			reverse[i] = '-';//append the '-' sign to reverse string
			i++;//increase counter value to compensate
		}
		reverse[i] = '\0';//conclude reverse string w/ null char to ensure proper reading of string
		while (i > 0)//since starting in 2nd to last pos and moving left
		{
			str[j] = reverse[i - 1];//i - 1 b/c the last pos is '\0'
			i--;//decrease i to move left, it will end up at 0
			j++;//increase j to move right in str
		}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(void)
{
	int	nb;

	nb = -2147483647;
	ft_putnbr(nb);
	return (0);
}
