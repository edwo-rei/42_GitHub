/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:15:18 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/15 21:22:26 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//helper function to split find_target_index_a. check if targ_i greater
//than last node value. If so, return 0, pos is good. Otherwise,
//loop thru list while <, then loop thru while >. At end of
//2nd loop will be the target index	
int	find_tia_help(t_list *stack, int value, int i)
{
			t_list	*last;
			
			last = go_to_last(stack);
			if (value > last->value)
				return (0);
			while (value < stack->value)
			{
				stack = stack->next;
				i++;
			}
			while (value > stack->value)
			{
				stack = stack->next;
				i++;
			}
			return (i);
}

//find the index of the smallest # higher than a given node
int	find_target_index_a(t_list *stack, int value)
{
	int	i;

	i = 0;
	//if value is new max or min, find index of current min & return it
	if (value > find_max_value(stack) || value < find_min_value(stack))
		return (find_min_pos(stack));
	else
	{
		//if value is greater than stack head value, go down the list
		//until encountering a node value greater than value
		if (value > stack->value)
		{
			//increase index by 1 for each node traversed
			while (value > stack->value)
			{
				stack = stack->next;
				i++;
			}
		}
		//if value is less than stack head value, call helper function 
		else
			i = find_tia_help(stack, value, i);
	}
	return (i);
}

//if value is greater than stack head value, check if it less
//than last node value. If so, return 0, pos is good. Otherwise,
//loop thru list while >, then loop thru while <. At end of
//2nd loop will be the target index	
int	find_tib_help(t_list *stack, int value, int i)
{
			t_list	*last;
			
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
			return (i);
}

//find the index of the highest # smaller than a given node
int	find_target_index_b(t_list *stack, int value)
{
	int	i;

	i = 0;
	//if value is new max or min, find index of current max & return it
	if (value > find_max_value(stack) || value < find_min_value(stack))
		return (find_max_pos(stack));
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
		//if value is greater, call helper function
		else
			i = find_tib_help(stack, value, i);
	}
	return (i);
}
