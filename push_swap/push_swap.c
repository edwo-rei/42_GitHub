/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:02:46 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/11 13:29:12 by edwo-rei         ###   ########.fr       */
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

//check if the #s in the stack are already in ascending order
int	check_if_sorted(t_list *stack)
{
	t_list	*current;

	//necessary to check that stack_a isn't null?
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		else
			current = current->next;
	}
	return (1);
}

//function to initialize variables & save lines
void	init_vars(t_list **stack_a, t_list **stack_b, char ***args, int	*count)
{
	//it's good practice to initialize ptrs to NULL to avoid using
	//uninitialized ptrs & to prevent undefined behavior like accessing
	//garbage memory ("defensive programming")
	*stack_a = NULL;
	*stack_b = NULL;
	*args = NULL;
	*count = 0;
}

//function to set count & args if input != string & to save lines
void	set_count_args(int argc, int *count, char **argv, char ***args)
{
	*count = argc - 1;
	*args = argv + 1;
} 

int	main(int argc, char *argv[])
{
	//declare variables for stacks a * b (singly linked lists - doubly-linked
	//circular linked lists didn't end up being necessary)
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	int		count;

	//init all ptrs to NULL
	init_vars(&stack_a, &stack_b, &args, &count);
	//If no args, just return to prompt
	if (argc < 2)
		return (0);
	//mechanism to deal with a string of numbers
	else if (argc == 2)
	{
		count = count_args(argv[1], ' ');
		args = ft_split(argv[1], ' ');
		//changed from 2 to 1, b/c just 1 # isn't necessarily an error
		if (count < 1 || !args)
			print_error(argc, count, args);
	}
	//set count & args if not input as a string
	else
		set_count_args(argc, &count, argv, &args);
	//check if string is all ints, if any int is a duplicate or is 
	//outside max range
	validate_input(argc, count, args);
	//create a linked list w/ #s given in cmd line args & assign to stack_a
	stack_a = create_stack(count, args);
	//check if input is already sorted & apply sort algorithm if not
	if (!(check_if_sorted(stack_a)))
		sort(&stack_a, &stack_b, count);
	free_stack(&stack_a);
	free_stack(&stack_b);//necessary?
	if (argc == 2)
		free_args(count, args);
}
