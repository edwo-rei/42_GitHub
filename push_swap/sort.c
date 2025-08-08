/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:59:44 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/08 19:33:18 by edwo-rei         ###   ########.fr       */
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

// This function decides what sorting method needs to be applied based on the #
// of args
void	sort(t_list **stack_a, int argc)
{
	// If there are only 2 args & they're not already sorted, they just need 
	// to be swapped
	if (argc == 2)
		swap_a(stack_a);
	// If there are only 3 args, just apply the sort_3 function
	else if (argc == 3)
		sort_3(stack_a);
}
