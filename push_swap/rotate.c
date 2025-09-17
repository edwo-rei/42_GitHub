/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:43:15 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/07 19:39:11 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//make the first element of stack_a the last, and the second the first
void	rotate_a(t_list **stack_a)
{
	t_list	*tmp;

	if (!*stack_a || !((*stack_a)->next))
		return;
	//tmp points to node at top of stack_a
	tmp = *stack_a;
	//make stack_a point to last node in the list
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	//make last node in list point to previous top node
	(*stack_a)->next = tmp;
	//make stack_a point to node that top node was previously pointing at
	*stack_a = tmp->next;
	//set previous top node's next var to point to NULL, making it the 
	//end of the list
	tmp->next = NULL;
	//register action by writing "ra"
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_b || !((*stack_b)->next))
		return;
	//tmp points to node at top of stack_b
	tmp = *stack_b;
	//make stack_b point to last node in the list
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	//make last node in list point to previous top node
	(*stack_b)->next = tmp;
	//make stack_b point to node that top node was previously pointing at
	*stack_b = tmp->next;
	//set previous top node's next var to point to NULL, making it the
	//end of the list
	tmp->next = NULL;
	//register action by writing "rb"
	write(1, "rb\n", 3);
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	
	if (!*stack_a || !((*stack_a)->next) 
			|| !*stack_b || !((*stack_b)->next))
		return;
	tmp = *stack_a;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	tmp = *stack_b;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	write(1, "rr\n", 3);
}
