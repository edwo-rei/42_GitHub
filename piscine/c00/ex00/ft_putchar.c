/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:44:15 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/03/25 13:37:34 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>//includes the header that names the library with the function write

void	ft_putchar(char c)//void means it won't produce a return value. The function takes the variable named c, of the character type, as its input
{
	write(1, &c, 1);//writes to standard output (1), from  the memory address of the variable c (&c), and the output will be 1 byte (1 character takes up 1 byte)
}
