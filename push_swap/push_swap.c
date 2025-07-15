/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:02:46 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/14 20:40:06 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int value)
{
	t_list	*node;

	//defensive programming
	node = NULL;
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);//any reason it'd be necessary to free new?
	node->value = value;
	node->next = NULL;
	return (node);
}

int	main(int argc, char *argv[])
{
	//declare variables for stacks a * b (circular linked lists?)
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;
	int		i;

	//guard against no args
	if (argc < 2)
		return (0);
	//it's good practice to initialize ptrs to NULL to avoid using
	//uninitialized ptrs & to prevent undefined behavior like accessing
	//garbage memory ("defensive programming")
	stack_a = NULL;
	stack_b = NULL;
	tmp = NULL;
	//mechanism to deal with an unknown # of args
	i = 1;
	while (i < argc)
	{
		//check if string is an int
		//check if int is a duplicate
		//allocate memory for each input
		tmp = new_node(ft_atoi(argv[i]));
		tmp->next = stack_a;
		stack_a = tmp;
		i++;
	}
	while (stack_a)
	{
		printf("%i\n", stack_a->value);
		stack_a = stack_a->next;
	}
}
