/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:26:54 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/16 19:39:11 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int	i;

	//use tmp ptr variable to avoid altering lst ptr position
	tmp = lst;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*head;
	t_list	*new;
	int	a = 42;
	int	b = 7;

	head = ft_lstnew(&a);
	new = ft_lstnew(&b);
	ft_lstadd_front(&head, new);
	printf("# of nodes: %i\n", ft_lstsize(head));
}*/
