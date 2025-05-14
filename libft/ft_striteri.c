/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:08:51 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/12 20:17:58 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*address of char to be modified is passed to function pointed to, then this 
  function moves to next char in s*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*function makes char whose address is passed upper case if index # is even.
 Index not used to modify char because address of char to be modified is
 already being passed
void	function(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = ft_toupper(*c);
}

int	main(void)
{
	char	s[] = "This is a test string.";

	ft_striteri(s, function);
	printf("%s\n", s);
}*/
