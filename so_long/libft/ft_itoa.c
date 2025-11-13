/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:27:32 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/09 19:55:55 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Obtain length needed for string that int n will be converted into
static int	get_len(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/*Allocate mem for str, put chars in str in reverse order, return str*/
char	*ft_itoa(int n)
{
	int		len;
	int		i;
	long	ln;
	char	*str;

	len = get_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	ln = n;
	if (n < 0)
	{
		str[0] = '-';
		ln = ln * -1;
	}
	i = len - 1;
	while (ln != 0)
	{
		str[i--] = ln % 10 + 48;
		ln = ln / 10;
	}
	str[len] = '\0';
	return (str);
}
