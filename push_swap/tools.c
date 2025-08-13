/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:33:26 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/12 12:54:47 by edwo-rei         ###   ########.fr       */
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

//find node w/ min value & return # of steps away from head
int	find_min_pos(t_list *stack_a)
{
	//i will be used to compare values between nodes
	int	i;
	int	pos;
	int	min_pos;

	i = stack_a->value;
	//pos & min_pos used to ID where min value is & determine min # of
	//mvmts needed to bring to head of stack_a
	pos = 0;
	min_pos = 0;
	while (stack_a)
	{
		//check each node to see if its value is < min encountered
		//so far. If so, change i to that value
		if (stack_a->value < i)
		{
			i = stack_a->value;
			min_pos = pos;
		}
		stack_a = stack_a->next;
		pos++;
	}
	return (min_pos);
}

void	raise_min(t_list **stack_a, t_list **stack_b, int argc, int min_pos)
{
	int	i;

	i = 0;
	//rotate until min value is at top of stack_a
	if (min_pos <= argc / 2)
	{
		while (i < min_pos)
		{
			rotate_a(stack_a);
			i++;
		}
	}
	else
	{
		while (min_pos + i < argc)
		{
			reverse_rotate_a(stack_a);
			i++;
		}
	}
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
