/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:06:15 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/04/28 11:13:15 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (c);
	return (0);
}
/*chars passed to isalpha are auto-promoted to int equal to their ascii value
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("%i\n", isalpha(argv[1][0]));
		printf("%i\n", ft_isalpha(argv[1][0]));
	}
}*/
