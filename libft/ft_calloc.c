/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:16:53 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/09 11:45:47 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = malloc(count * size);
	if (mem == 0)
		return (NULL);
	while (i < count * size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
/*
int	main(void)
{
	size_t	count;
	size_t	size;
	unsigned char	*mem;


	count = 5;
	size = sizeof(int);
	mem = calloc(count, size);
	printf("%p\n", mem);
	printf("%s\n", mem);
	free(mem);
	mem = ft_calloc(count, size);
	printf("%p\n", mem);
	printf("%s\n", mem);
	free(mem);
}*/
