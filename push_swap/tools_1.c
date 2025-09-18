/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:28:45 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/13 19:32:36 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*go_to_last(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
		return (NULL);
	//use tmp ptr variable to avoid altering lst ptr position
	tmp = stack;
	//loop through nodes until reaching one where next == NULL
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	find_stack_size(t_list *stack)
{
	t_list	*tmp;
	int	i;

	//use tmp ptr variable to avoid altering lst ptr position
	tmp = stack;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

//raise node w/ min value to the top of the stack
void	raise_min_a(t_list **stack_a, int argc, int min_pos)
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

//raise node w/ max value to the top of the stack_b
void	raise_max_b(t_list **stack_b, int stack_size, int target_i)
{
	int	i;

	i = 0;
	//rotate until max value is at top of stack_a
	if (target_i <= stack_size / 2)
	{
		while (i < target_i)
		{
			rotate_b(stack_b);
			i++;
		}
	}
	else
	{
		while (target_i + i < stack_size)
		{
			reverse_rotate_b(stack_b);
			i++;
		}
	}
}

//raise node w/ target value to the top of the stack_a
void	raise_target_a(t_list **stack_a, int stack_size, int target_i)
{
	int	i;

	i = 0;
	//rotate until target value is at top of stack_a
	if (target_i <= stack_size / 2)
	{
		while (i < target_i)
		{
			rotate_a(stack_a);
			i++;
		}
	}
	else
	{
		while (target_i + i < stack_size)
		{
			reverse_rotate_a(stack_a);
			i++;
		}
	}
}
