/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:13:35 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/09/18 14:16:43 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

long	ft_atol(const char *str)
{
	int		i;
	long	n;
	int		sign;

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

//return # of rot or rev. rotations based on where the target index is
int	rot_or_revrot(int index, int stack_size)
{
	if (index <= stack_size / 2)
		return (index);
	else
		return ((stack_size - index) * -1);
}

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
