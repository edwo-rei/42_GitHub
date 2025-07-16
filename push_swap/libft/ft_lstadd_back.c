/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:51:46 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/16 20:15:42 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//uses a ptr to a ptr because we need to change the address of the head of the list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return;
	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

/*creates new list node w/ content pointing to b, adds new node to tail. Prints
  content of all nodes. Must cast return value to (int *) and then dereference 
  b/c structure variable type for content is void
int	main(void)
{
	t_list	*head;
	t_list	*new;
	t_list	*last;
	int	a = 42;
	int	b = 7;

	head = ft_lstnew(&a);
	new = ft_lstnew(&b);
	printf("head content: %i\n", *(int *)(head->content));
	printf("new content: %i\n", *(int *)(new->content));
	ft_lstadd_back(&head, new);
	printf("head content: %i\n", *(int *)(head->content));
	last = ft_lstlast(head);
	printf("last content: %i\n", *(int *)(last->content));
}*/
