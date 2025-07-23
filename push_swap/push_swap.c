/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:02:46 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/23 14:05:26 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//count the quantity of #s given in a string
static int	count_args(const char *s, char c)
{
	int	wc;
	int	in_arg;

	wc = 0;
	in_arg = 0;
	while (*s)
	{
		if (*s != c && in_arg == 0)
		{
			in_arg++;
			wc++;
		}
		else if (*s == c)
			in_arg = 0;
		s++;
	}
	return (wc);
}

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

int	main(int argc, char *argv[])
{
	//declare variables for stacks a * b (circular linked lists?)
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*ptr;
	t_list	*new;//change to new_node for clarity?
	int		i;

	//it's good practice to initialize ptrs to NULL to avoid using
	//uninitialized ptrs & to prevent undefined behavior like accessing
	//garbage memory ("defensive programming")
	stack_a = NULL;
	stack_b = NULL;
	ptr = NULL;
	i = 0;
	//guard against no args
	if (argc < 2 || (argc == 2 && !argv[1][0]))//2nd condition necessary?
		return (0);
	//mechanism to deal with a string of numbers
	else if (argc == 2)
	{
		argc = count_args(argv[1], ' ');
		argv = ft_split(argv[1], ' ');
	}
	//remove prog name from argc & argv to make uniform w/ result of split
	else
	{
		argc--;
		argv++;
	}
	//check if string is all ints
	check_digits(argc, argv);
	//check if any int is a duplicate
	//mechanism to deal with an unknown # of args
	while (i < argc)
	{
		//allocate memory for each input
		new = create_node(ft_atoi(argv[i]));
		//add new node w/ each new input to bottom of stack
		if (stack_a)
		{
			//tmp ptr carries us to the node at the end of the list,
			//then assigns its next field to point to the new node
			ptr = stack_a;
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = new;
		}
		else
			stack_a = new;
		//make circular at later point to facilitate rotation?
		i++;
	}
	//temp mechanism to display what's in stack_a
	while (stack_a)
	{
		printf("%i\n", stack_a->value);
		stack_a = stack_a->next;
	}
}
