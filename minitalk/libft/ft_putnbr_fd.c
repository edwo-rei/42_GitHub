/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:15:58 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/09 19:58:41 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
	{
	char	reverse[12];
	int		i;
	long	ln;

	i = 0;
	ln = n;
	if (ln == 0)
		write(fd, "0", 1);
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	while (ln != 0)
	{
		reverse[i++] = (ln % 10) + 48;
		ln /= 10;
	}
	while (i > 0)
		write(fd, &reverse[--i], 1);
}
