/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:38:22 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/09 20:02:20 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*(unsigned int, char) aren't parameters, they indicate what kind of parameters 
  the function pointed to must take*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
