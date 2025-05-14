/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:16:56 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/23 17:16:20 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int	i;

	i = 48;//ASCII decimal vale for the char '0'
	while (i <= 57)//ASCII code for the char '9' 
	{
		write(1, &i, 1);
		++i;
	}
}
