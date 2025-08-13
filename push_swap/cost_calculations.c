/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:15:18 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/13 20:16:28 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//find the index of the highest # smaller than a given node
int	find_target_index(t_list *stack, int value)
{
	int	i;

	i = 0;
	//increase index by 1 for each node
	while (value < stack->value)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}


//find the the # of rotations or reverse_rotations stack_b would need to make
//so that push_to_b would result in pushed value being in the right pos 
int	find_rotations(t_list *stack, int value)
{
	int	rotations;
	int	stack_size;
	int	target_index;
	t_list	*last_node;

	last_node = go_to_last(stack);
	stack_size = find_stack_size(stack);
	if (value > stack->value)
		rotations = 0;
	else if (value < last_node->value)
		rotations = 1;
	else
	{
		target_index = find_target_index(stack);
		if (target_index < stack_size / 2)
			rotations = target_index;
		else
			rotations = stack_size - target_index;
	}
	return (rotations);
}
