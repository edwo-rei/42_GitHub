/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:33:26 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/11 12:30:59 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long	ft_atol(const char *str)
{
	int	i;
	long	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((9 <= str[i] && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		n *= 10;
		n += str[i] - 48;
		i++;
	}
	return (n * sign);
}
/*
int	main(void)
{
	char	pos[] = "2000247483650";
	char	neg[] = "-10247483658";
	char	mix[] = "	-2468tx";
	char	empty[] = "";

	printf("atol pos: %li\n", atol(pos));
	printf("ft_atol pos: %li\n", ft_atol(pos));
	printf("atol neg: %li\n", atol(neg));
	printf("ft_atol neg: %li\n", ft_atol(neg));
	printf("atol mix: %li\n", atol(mix));
	printf("ft_atol mix: %li\n", ft_atol(mix));
	printf("atol empty: %li\n", atol(empty));
	printf("ft_atol empty: %li\n", ft_atol(empty));
}*/

//Free stack by freeing top node & all subsequent nodes until none remain
void	free_stack(t_list **stack)
{
	t_list	*current;

	//set current to point to the same node as stack ptr, set stack ptr
	//to point to next node & free current node
	while (*stack)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}
