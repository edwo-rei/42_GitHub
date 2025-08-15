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
int	find_rot_b(t_list *stack, int value)
{
	int	stack_size;
	int	target_index;

	stack_size = find_stack_size(stack);
	target_index = find_target_index(stack, value);
	//returns + #s for ra & -#s for rra, 0 if already in right pos
	if (target_index <= stack_size / 2)
		return (target_index);
	else
		return ((stack_size - target_index) * -1);
}

int	find_cost(t_list *stack_a, t_list *stack_b, int index, int value)
{
	int	rot_a;
	int	rot_b;
	int	stack_size;
	
	//find # of rotations to bring current node to top of a
	stack_size = find_stack_size(stack_a);
	if (index <= stack_size / 2)
		rot_a = index;
	else
		rot_a = (stack_size - index) * -1;
	//find # of rotations of b needed for current node to go in right place
	rot_b = find_rot_b(stack_b, value);
	//sum those rotations to find total cost of move
	// - if rot_a * rot_b is pos, they rotate in same direction, so return
	//   larger of the two
	if (rot_a * rot_b > 0)
	{
		if (ft_abs(rot_a) > ft_abs(rot_b))
			return (ft_abs(rot_a));
		else
			return (ft_abs(rot_b));
	}
	//if rot_a * rot_b is neg, they rotate in diff directions, so return the
	//sum of the rotations in opposite directions
	else if (rot_a * rot_b < 0)
		return (ft_abs(rot_a - rot_b));
	//if rot_a * rot_b = 0, at least one of the two is 0, already in right
	//pos, so just need to return the other # of rotations - which may also
	//be 0
	else
	{
		if (rot_a != 0)
			return (ft_abs(rot_a));
		else
			return (ft_abs(rot_b));
	}
}

//find node in stack_a w/ min cost to push to stack_b in proper place
int	find_min_cost(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	min_pos;
	int	cost;
	int	min_cost;
	t_list	*tmp;

	i = 0;
	tmp = stack_a;
	cost = find_cost(stack_a, stack_b, i, tmp->value);
	min_cost = cost;
	min_pos = i;
	//if the head node requires no maneuvers for a pb to put it in the 
	//right place, it should just be pushed, so return 0 index
	if (cost == 0)
			return (0);
	//loop thru stack_a saving as min_pos any index for a nod w/ a min cost
	//less than the previous min cost
	while (tmp)
	{
		cost = find_cost(stack_a, stack_b, i, tmp->value);
		if (cost < min_cost)
		{
			min_cost = cost;
			min_pos = i;
		}
		printf("i: %i cost: %i min_cost: %i min_pos: %i value: %i\n", i, cost, min_cost, min_pos, tmp->value);
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}
