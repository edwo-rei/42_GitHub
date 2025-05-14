/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:33:38 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/21 12:49:29 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)//will take no parameters, thus void in the parameter space
{
	char	c;//defines the char variable c

	c = 'a';//initializes c with the value of 'a' (ASCII equivalent of 97)
	while (c <= 'z')//run this while loop while c variable has ASCII value less than or equal to that of 'z'
	{
		write(1, &c, 1);
		++c;//increase the value of c to move forward a character in the while loop
	}
}
