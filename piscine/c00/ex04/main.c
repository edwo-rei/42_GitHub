/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:47:46 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/23 18:51:04 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void	ft_is_negative(int i);

int	main(void)
{
	ft_is_negative(42);
	ft_is_negative(0);
	ft_is_negative(-42);
	return (0);
}
