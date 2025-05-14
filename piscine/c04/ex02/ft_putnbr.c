/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:07:03 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/06 15:56:38 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb)//convert int to chars that can be displayed w/ write
{
	char	reverse[12];//string will hold input #s in reverse
	int		i;//counter
	long	lnb;

	i = 0;
	lnb = nb;//long int necessary for -2147483648
	if (lnb == 0)
	{
		write(1, "0", 1);
	}
	if (lnb < 0)//if negative
	{
		write(1, "-", 1);//write "-" sign
		lnb *= -1;//make positive (won't work with int -2147483648 b/c it will be turned into 2147483648, which doesn't fit into range of integers. Pos #s in binary start w/ 0, as does 0, so there is 1 more # in neg direction.
	}
	while (lnb != 0)
	{
		reverse[i++] = (lnb % 10) + 48;//will first assign ASCII of # to reverse[i], then increase i by 1
		lnb /= 10;//divide # by 10 to remove digit in one's place
	}
	while (i > 0)
	{
		write(1, &reverse[--i], 1);//first subtract 1 from i, then write char in reverse[i] pos
	}
}

int	main(void)
{
	ft_putnbr(42);
	write(1, "\n", 1);
	ft_putnbr(-42);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(2147483647);//hightest int
	write(1, "\n", 1);
	ft_putnbr(-2147483648);//lowest int
	return (0);
}
