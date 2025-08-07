/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:42:43 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/07 18:06:46 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Take top element of stack_a & put at top of stack_b. Parameters are the 
//addresses of the pointers to stack_a & stack_b b/c we don't want to just
//copy the stack_a/b pointers, we need to modify the orignal stacks,
//specifically their heads. When we pass &stack_a, we can reassign the head node
void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	//create a temporary ptr to perform the swap
	t_list	*tmp;

	//If stack_a is null/doesn't point to a node, it's empty, there's
	//nothing to push, just return
	if (!*stack_a)
		return;
	//set tmp ptr to head of stack_b
	tmp = *stack_b;
	//reassign stack_b ptr to point to node at top of stack_a
	*stack_b = *stack_a;
	//reassign stack_a ptr to point to node that was 2nd to top of stack_a
	*stack_a = (*stack_a)->next;
	//connect node stack_b's now pointing at to node that was top of stack_b
	(*stack_b)->next = tmp;
	//write pb to record the operation
	write(1, "pb\n", 3);
}

//Take top element of stack_b & put at top of stack_a
void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_b)
		return;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	write(1, "pa\n", 3);
}
