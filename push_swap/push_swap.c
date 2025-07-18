/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:02:46 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/16 20:36:25 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *s, char c)
{
	int	wc;
	int	word;

	wc = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && word == 0)
		{
			word++;
			wc++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (wc);
}

t_list	*new_node(int value)//change to create_node for clarity?
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
	t_list	*tmp;//change name to ptr to clarify its use?
	t_list	*new;//change to new_node for clarity?
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
	i = 1;
	//mechanism to deal with a string of numbers
	if (argc == 2)
	{
		argc = count_words(argv[1], ' ');
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	//mechanism to deal with an unknown # of args
	while (i < argc)
	{
		//check if string is an int
		//check if int is a duplicate
		//allocate memory for each input
		new = new_node(ft_atoi(argv[i]));
		//add new node w/ each new input to bottom of stack
		if (stack_a)
		{
			//tmp ptr carries us to the node at the end of the list,
			//then assigns its next field to point to the new node
			tmp = stack_a;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
			stack_a = new;
		//tmp->next = stack_a;
		//stack_a = tmp;
		i++;
	}
	//temp mechanism to display what's in stack_a
	while (stack_a)
	{
		printf("%i\n", stack_a->value);
		stack_a = stack_a->next;
	}
}
