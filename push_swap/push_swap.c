/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:02:46 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/01 19:38:58 by edwo-rei         ###   ########.fr       */
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
int	check_if_sorted(t_list *stack_a)
{
	t_list	*current;

	//necessary to check that stack_a isn't null?
	current = stack_a;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		else
			current = current->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	//declare variables for stacks a * b (circular linked lists?)
	t_list	*stack_a;
	t_list	*stack_b;

	//it's good practice to initialize ptrs to NULL to avoid using
	//uninitialized ptrs & to prevent undefined behavior like accessing
	//garbage memory ("defensive programming")
	stack_a = NULL;
	stack_b = NULL;
	//guard against no args
	if (argc < 2 || (argc == 2 && !argv[1][0]))//2nd condition necessary?
		return (0);
	//mechanism to deal with a string of numbers
	else if (argc == 2)
	{
		argc = count_args(argv[1], ' ');
		argv = ft_split(argv[1], ' ');
		if (argc < 2)
			print_error();
	}
	//remove prog name from argc & argv to make uniform w/ result of split
	else
	{
		argc--;
		argv++;
	}
	//check if string is all ints, if any int is a duplicate or is 
	//outside max range
	validate_input(argc, argv);
	//create a linked list w/ #s given in cmd line args & assign to stack_a
	stack_a = create_stack(argc, argv);
	if (check_if_sorted(stack_a))
		printf("Stack is already sorted\n");
	else
		printf("Stack is not sorted\n");
	//temp mechanism to display what's in stack_a
	while (stack_a)
	{
		printf("%i\n", stack_a->value);
		if (stack_a->next == NULL)
			break;
		stack_a = stack_a->next;
	}
	/*temp mechanism to check if list is double-linked
	while (stack_a)
	{
		printf("%i\n", stack_a->value);
		stack_a = stack_a->prev;
	} - NOT SURE IF I WANT TO DOUBLE LINK*/
}
