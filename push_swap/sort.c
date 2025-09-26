/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:59:44 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/09/22 11:31:49 by edwo-rei         ###   ########.fr       */
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

//ID node w/ min cost to move to stack_b & push it until only 3 remain
void	sort_to_b(t_list **stack_a, t_list **stack_b, int stack_size)
{
	int	target_i;

	while (stack_size > 3 && (!(check_if_sorted(*stack_a))))
	{
		target_i = find_min_cost(*stack_a, *stack_b);
		//identify most econ way to move stacks into proper pos for pb
		//execute most economic way of moving stacks into proper pos
		position_stacks(stack_a, stack_b, target_i);
		//push node w/ min value to stack_b
		push_to_b(stack_a, stack_b);
		stack_size--;
	}
}

void	sort_5_plus(t_list **stack_a, t_list **stack_b, int argc)
{
	int	stack_size;
	int	i;
	int	target_i;

	//account for 2 nodes pushed to b
	stack_size = argc - 2;
	//calc min cost of pushing each node to be & push that node
	sort_to_b(stack_a, stack_b, stack_size);	
	//once all but 3 nodes are in stack_b, rotate it until max value is at top
	stack_size = find_stack_size(*stack_b);
	target_i = find_max_pos(*stack_b);
	if (!(check_if_sorted(*stack_b)))
		raise_max_b(stack_b, stack_size, target_i);
	if (!(check_if_sorted(*stack_a)))
		sort_3(stack_a);
	//push min back to stack_a, which will now be in ascending order
	i = stack_size;
	//raise the lowest value that is more than the head of stack_b to the top of
	//stack_a & push the value at top of stack_b to stack_a
	while (i > 0)
	{
		target_i = find_target_index_a(*stack_a, (*stack_b)->value);
		stack_size = find_stack_size(*stack_a);
		raise_target_a(stack_a, stack_size, target_i); 
		push_to_a(stack_a, stack_b);
		i--;
	}
	stack_size = find_stack_size(*stack_a);
	target_i = find_min_pos(*stack_a);
	if (!(check_if_sorted(*stack_a)))
		raise_target_a(stack_a, stack_size, target_i);
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
	else
	{
		//push top 2 nodes in stack_a to stack_b
		push_to_b(stack_a, stack_b);
		push_to_b(stack_a, stack_b);
		sort_5_plus(stack_a, stack_b, argc);
	}
}
