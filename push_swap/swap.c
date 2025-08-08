/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:41:21 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/07 18:06:00 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Take top element of stack_a & swap it w/ next element. Parameters are the
//addresses of the pointers to stack_a & stack_b b/c we don't want to just
//copy the stack_a/b pointers, we need to modify the orignal stacks,
//specifically their heads. When we pass &stack_a, we can reassign the head node
void	swap_a(t_list **stack_a)
{
	//create a temporary ptr to perform the swap
	t_list	*tmp;

	//If stack_a is empty or the top node's next variable points to NULL,
	//no swap can be made, so just return
	if (!*stack_a || !((*stack_a)->next))
		return;
	//set tmp ptr to head of stack_a
	tmp = *stack_a;
	//reassign stack_a ptr to point to node that was 2nd to top of stack_a
	*stack_a = (*stack_a)->next;
	//reassign next var of node that was top of stack_a to point to what 
	//next var of node 2nd to top was pointing to
	tmp->next = (*stack_a)->next;
	//reassign stack_a's next var to point to node that was top of stack_a
	(*stack_a)->next = tmp;
	//write sa to record the operation
	write(1, "sa\n", 3);
}

//Take top element of stack_b & swap it w/ next element using tmp ptr var
void	swap_b(t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_b || !((*stack_b)->next))
		return;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	write(1, "sb\n", 3);
}

//swap tops of both stack_a & stack_b
void	swap_both(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	write(1, "ss\n", 3);
}
