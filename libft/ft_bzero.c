/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:16:50 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/29 19:49:42 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}
/*
int	main(void)
{
	char	str1[] = "test-string";
	char	str2[] = "test-string";
	size_t	n;

	n = 4 * sizeof(char);
	bzero(str1, n);
	printf("bzero returns: %s\n", str1);
	printf("left over: %s\n", &str1[4]);
	ft_bzero(str2, n);
	printf("ft_bzero returns: %s\n", str2);
	printf("left over: %s\n", &str2[4]);
	return (0);
}*/
