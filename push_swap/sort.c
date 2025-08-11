/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:59:44 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/11 14:19:14 by edwo-rei         ###   ########.fr       */
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
	//current will be used to loop thru stack_a
	t_list	*current;
	//i will be used to compare values between nodes
	int	i;
	int	pos;
	int	min_pos;

	//set current to head node & i to its value to start
	current = *stack_a;
	i = current->value;
	//pos & min_pos used to ID where min value is & determine min # of
	//mvmts needed to bring to head of stack_a
	pos = 0;
	min_pos = 0;
	while (current)
	{
		//check each node to see if its value is < min encountered
		//so far. If so, change i to that value
		if (current->value < i)
		{
			i = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	//rotate until min value is at top of stack_a
	if (min_pos < 3)
		while ((*stack_a)->value != i)
			rotate_a(stack_a);
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
}
