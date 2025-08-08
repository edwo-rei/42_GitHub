/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:43:41 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/08 13:24:16 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//make the last element of stack_a the 1st, and the penultimate the last
void	reverse_rotate_a(t_list **stack_a)
{
	t_list	*current;
	t_list	*penultimate;

	if (!*stack_a || !((*stack_a)->next))
		return;
	//current points to node at top of stack_a
	current = *stack_a;
	//penultimate points to node at top of stack_a
	penultimate = *stack_a;
	//make current point to last node in the list
	while (current->next)
		current = current->next;
	//make penultimate point to penultimate node in the list
	while (penultimate->next->next)
		penultimate = penultimate->next;
	//make last node in list point to top node
	current->next = *stack_a;
	//make 2nd to last node point to NULL, converting it into last node
	penultimate->next = NULL;
	//make stack_a point to what was the last node
	*stack_a = current;
	//register action by writing "ra"
	write(1, "rra\n", 4);
}

//make the last element of stack_b the 1st, and the penultimate the last
void	reverse_rotate_b(t_list **stack_b)
{
	t_list	*current;
	t_list	*penultimate;

	if (!*stack_b || !((*stack_b)->next))
		return;
	current = *stack_b;
	penultimate = *stack_b;
	while (current->next)
		current = current->next;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	current->next = *stack_b;
	penultimate->next = NULL;
	*stack_b = current;
	write(1, "rrb\n", 4);
}

//make the last elements of both stacks the 1st, and the penultimate the last
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	t_list	*penultimate;

	if (!*stack_a || !((*stack_a)->next) 
			|| !*stack_b || !((*stack_b)->next))
		return;
	current = *stack_a;
	penultimate = *stack_a;
	while (current->next)
		current = current->next;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	current->next = *stack_a;
	penultimate->next = NULL;
	*stack_a = current;
	current = *stack_b;
	penultimate = *stack_b;
	while (current->next)
		current = current->next;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	current->next = *stack_b;
	penultimate->next = NULL;
	*stack_b = current;
	write(1, "rrr\n", 4);
}
