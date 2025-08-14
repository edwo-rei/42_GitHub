/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:15:18 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/14 14:03:42 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//find the index of the highest # smaller than a given node
int	find_target_index(t_list *stack, int value)
{
	int	i;
	t_list	*last;

	i = 0;
	if (value > find_max_value(stack) || value < find_min_value(stack))
		return (0);
	else
	{
		//if value is less than stack head value, go down the list
		//until encountering a node value less than value
		if (value < stack->value)
		{
			//increase index by 1 for each node traversed
			while (value < stack->value)
			{
				stack = stack->next;
				i++;
			}
		}
		//if value is greater than stack head value, check if it less
	       	//than last node value. If so, return 0, pos is good. Otherwise,
		//loop thru list while >, then loop thru while <. At end of
		//2nd loop will be the target index	
		else
		{
			last = go_to_last(stack);
			if (value < last->value)
				return (0);
			while (value > stack->value)
			{
				stack = stack->next;
				i++;
			}
			while (value < stack->value)
			{
				stack = stack->next;
				i++;
			}
		}
	}
	return (i);
}


//find the the # of rotations or reverse_rotations stack_b would need to make
//so that push_to_b would result in pushed value being in the right pos. My plan
//is to always have stack_b organized in descending order 
int	find_rotations_b(t_list *stack, int value)
{
	int	stack_size;
	int	target_index;

	stack_size = find_stack_size(stack);
	target_index = find_target_index(stack, value);
	if (target_index == 0)
		return (0);
	else if (target_index <= stack_size / 2)
		return (target_index);
	else
		return (stack_size - target_index);
}
