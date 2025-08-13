/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:28:45 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/13 19:32:36 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*go_to_last(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
		return (NULL);
	//use tmp ptr variable to avoid altering lst ptr position
	tmp = stack;
	//loop through nodes until reaching one where next == NULL
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	find_stack_size(t_list *stack)
{
	t_list	*tmp;
	int	i;

	//use tmp ptr variable to avoid altering lst ptr position
	tmp = stack;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
