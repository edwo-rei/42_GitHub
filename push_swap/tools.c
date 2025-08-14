/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:33:26 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/14 19:01:20 by edwo-rei         ###   ########.fr       */
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
int	find_min_pos(t_list *stack)
{
	//i will be used to compare values between nodes
	int	i;
	int	pos;
	int	min_pos;

	i = stack->value;
	//pos & min_pos used to ID where min value is & determine min # of
	//mvmts needed to bring to head of stack_a
	pos = 0;
	min_pos = 0;
	while (stack)
	{
		//check each node to see if its value is < min encountered
		//so far. If so, change i to that value
		if (stack->value < i)
		{
			i = stack->value;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

//find node w/ max value & return # of steps away from head
int	find_max_pos(t_list *stack)
{
	//i will be used to compare values between nodes
	int	i;
	int	pos;
	int	max_pos;

	i = stack->value;
	//pos & min_pos used to ID where min value is & determine min # of
	//mvmts needed to bring to head of stack_a
	pos = 0;
	max_pos = 0;
	while (stack)
	{
		//check each node to see if its value is < min encountered
		//so far. If so, change i to that value
		if (stack->value > i)
		{
			i = stack->value;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}

//find min value in a stack & return it
int	find_min_value(t_list *stack)
{
	//i will be used to compare values between nodes
	int	i;

	i = stack->value;
	while (stack)
	{
		//check each node to see if its value is < min encountered
		//so far. If so, change i to that value
		if (stack->value < i)
			i = stack->value;
		stack = stack->next;
	}
	return (i);
}

int	find_max_value(t_list *stack)
{
	//i will be used to compare values between nodes
	int	i;

	i = stack->value;
	while (stack)
	{
		//check each node to see if its value is > min encountered
		//so far. If so, change i to that value
		if (stack->value > i)
			i = stack->value;
		stack = stack->next;
	}
	return (i);
}
