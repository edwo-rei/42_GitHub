/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:25:37 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/30 18:40:17 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//create new node & set its value to the one given as a parameter
t_list	*create_node(int value)
{
	t_list	*node;

	//defensive programming - really necessary?
	node = NULL;
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);//any reason it'd be necessary to free new?
	node->value = value;
	node->next = NULL;
	return (node);
}

t_list	*create_stack(int argc, char **argv)
{
	//declare variables for stacks a * b (circular linked lists?)
	t_list	*stack_a;
	t_list	*current;
	t_list	*new_node;
	int		i;

	//it's good practice to initialize ptrs to NULL to avoid using
	//uninitialized ptrs & to prevent undefined behavior like accessing
	//garbage memory ("defensive programming")
	stack_a = NULL;
	current = NULL;
	new_node = NULL;
	i = 0;
	//mechanism to deal with an unknown # of args
	while (i < argc)
	{
		//allocate memory for each input
		new_node = create_node(ft_atoi(argv[i]));
		//add new node w/ each new input to bottom of stack
		if (!stack_a)
			stack_a = new_node;
		else
		{
			//tmp ptr carries us to the node at the end of the list,
			//then assigns its next field to point to the new node
			current = stack_a;
			while (current->next)
				current = current->next;
			current->next = new_node;
		}
		//make circular at later point to facilitate rotation?
		i++;
	}
	return (stack_a);
}
