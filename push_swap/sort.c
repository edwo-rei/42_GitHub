/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:59:44 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/14 20:10:18 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// If there are only 3 args & they're not sorted, there are only 5 possible
// scenarios. This function decides what operations are necessary based on
// whether the value in the top node is > or < than the value in the next or
// last node.
void	sort_3(t_list **stack_a)
{
	if ((*stack_a)->value < (*stack_a)->next->value)
	{
		reverse_rotate_a(stack_a);
		if ((*stack_a)->value > (*stack_a)->next->value)
			swap_a(stack_a);
	}
	else
	{
		if ((*stack_a)->value > (*stack_a)->next->next->value)
			rotate_a(stack_a);
		if ((*stack_a)->value > (*stack_a)->next->value)
			swap_a(stack_a);
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	min_pos;

	i = 0;
	min_pos = find_min_pos(*stack_a);	
	//rotate until min value is at top of stack_a
	if (min_pos < 3)
		while (i < min_pos)
		{
			rotate_a(stack_a);
			i++;
		}
	else
		reverse_rotate_a(stack_a);
	//push node w/ min value to stack_b
	if (!(check_if_sorted(*stack_a)))
	{
		push_to_b(stack_a, stack_b);
		//order stack_a
		sort_3(stack_a);
		//push min back to stack_a, which will now be in ascending order
		push_to_a(stack_a, stack_b);
	}
}

void	sort_5(t_list **stack_a, t_list **stack_b, int argc)
{
	int	i;
	int	min_pos;

	i = argc;
	//ID node w/ min value
	while (i > 3 && (!(check_if_sorted(*stack_a))))
	{
		min_pos = find_min_pos(*stack_a);
		//rotate until min value is at top of stack_a
		raise_min_a(stack_a, i, min_pos);
		//push node w/ min value to stack_b
		push_to_b(stack_a, stack_b);
		i--;
	}
	if (!(check_if_sorted(*stack_a)))
		sort_3(stack_a);
	while (i < argc)
	{
		//push min back to stack_a, which will now be in ascending order
		push_to_a(stack_a, stack_b);
		i++;
	}
}

void	sort_6_plus(t_list **stack_a, t_list **stack_b, int argc)
{
	int	stack_size;
	int	i;
	int	target_i;
	t_list	*tmp;

	stack_size = argc;
	//push top 2 nodes in stack_a to stack_b
	push_to_b(stack_a, stack_b);
	stack_size--;
	push_to_b(stack_a, stack_b);
	stack_size--;
	//min_pos = find_min_cost(*stack_a, *stack_b);
	//printf("index of node to be pushed: %i\n", min_pos);
	//ID node w/ min cost to move to stack_b
	while (stack_size > 3 && (!(check_if_sorted(*stack_a))))
	{
		target_i = find_min_cost(*stack_a, *stack_b);
		//identify most economic way to move stacks a & b into proper pos for pb
		//execute most economic way of moving stacks a & b into proper pos for pb
		position_stacks(stack_a, stack_b, target_i);
		//push node w/ min value to stack_b
		push_to_b(stack_a, stack_b);
		stack_size--;
	}
	//once all but 3 nodes are in stack_b, rotate it until max value is at top
	stack_size = find_stack_size(*stack_b);
	target_i = find_max_pos(*stack_b);
	if (!(check_if_sorted(*stack_b)))
		raise_max_b(stack_b, stack_size, target_i);
	if (!(check_if_sorted(*stack_a)))
		sort_3(stack_a);
	//push min back to stack_a, which will now be in ascending order
	i = stack_size;
	while (i > 0)
	{
		target_i = find_target_index_a(*stack_a, (*stack_b)->value);
		stack_size = find_stack_size(*stack_a);
		printf("target_i: %i stack_size: %i\n", target_i, stack_size);
		//change name of raise_max_b to something more neutral, or replicate
		//function in a version for stack_a
		raise_max_b(stack_a, stack_size, target_i); 
		push_to_a(stack_a, stack_b);
		i--;
	}
	stack_size = find_stack_size(*stack_a);
	target_i = find_min_pos(*stack_a);
	if (!(check_if_sorted(*stack_a)))
		raise_max_b(stack_a, stack_size, target_i);
	//change function or name
}

// This function decides what sorting method needs to be applied based on the #
// of args
void	sort(t_list **stack_a, t_list **stack_b, int argc)
{
	// If there are only 2 args & they're not already sorted, they just need 
	// to be swapped
	if (argc == 2)
		swap_a(stack_a);
	// If there are only 3 args, just apply the sort_3 function
	else if (argc == 3)
		sort_3(stack_a);
	else if (argc == 4)
		sort_4(stack_a, stack_b);
	else if (argc == 5)
		sort_5(stack_a, stack_b, argc);
	else
		sort_6_plus(stack_a, stack_b, argc);
}
