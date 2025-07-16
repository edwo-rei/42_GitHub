/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:39:34 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/16 19:50:54 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	//use tmp ptr variable to avoid altering lst ptr position
	tmp = lst;
	//loop through nodes until reaching one where next == NULL
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
/*
int	main(void)
{
	t_list	*head;
	t_list	*new;
	t_list	*last;
	int	a = 42;
	int	b = 7;

	head = ft_lstnew(&a);
	new = ft_lstnew(&b);
	ft_lstadd_front(&head, new);
	last = ft_lstlast(head);
	printf("last node content: %i\n", *(int *)(last->content));
}*/
