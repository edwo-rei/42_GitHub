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
