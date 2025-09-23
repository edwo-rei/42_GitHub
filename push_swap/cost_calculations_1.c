/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:13:41 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/09/22 13:24:29 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//find the the # of rotations or reverse_rotations stack_b would need to make
//so that push_to_b would result in pushed value being in the right pos. My plan
//is to always have stack_b organized in descending order
int	find_rot_b(t_list *stack, int value)
{
	int	stack_size;
	int	target_index;

	stack_size = find_stack_size(stack);
	target_index = find_target_index_b(stack, value);
	//returns + #s for ra & -#s for rra, 0 if already in right pos
	if (target_index <= stack_size / 2)
		return (target_index);
	else
		return ((stack_size - target_index) * -1);
}

//find # of movements necessary to rotate stacks a & b into the proper pos to be 
//able to push the right node from stack a to stack b
int	find_cost(t_list *stack_a, t_list *stack_b, int index, int value)
{
	int	rot_a;
	int	rot_b;
	int	stack_size;

	//find # of rotations to bring current node to top of stack a
	stack_size = find_stack_size(stack_a);
	rot_a = rot_or_revrot(index, stack_size);
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
	//must use tmp ptr in order to maintain correct value of index from head 
	//of stack_a
	tmp = stack_a;
	cost = find_cost(stack_a, stack_b, i, tmp->value);
	min_cost = cost;
	min_pos = i;
	//if the head node requires no maneuvers for a pb to put it in the
	//right place, it should just be pushed, so return 0 index
	if (cost == 0)
			return (0);
	//loop thru stack_a saving as min_pos any index for a node w/ a min cost
	//less than the previous min cost
	while (tmp)
	{
		cost = find_cost(stack_a, stack_b, i, tmp->value);
		if (cost < min_cost)
		{
			min_cost = cost;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}
