/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:41:56 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/09 20:03:19 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*pbig;
	char	*plittle;
	size_t	i;

	pbig = (char *)big;
	plittle = (char *)little;
	if (*plittle == '\0')
		return (pbig);
	while (len && *pbig)
	{
		if (*pbig == *plittle)
		{
			i = 0;
			while ((len > i) && (pbig[i] == plittle[i]))
			{
				i++;
				if (plittle[i] == '\0')
					return (pbig);
			}
		}
		pbig++;
		len--;
	}
	return (0);
}
