/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:53:57 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/16 20:22:00 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//uses a ptr to a ptr because we need to change the address of the head of the list
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;//same as "(*new).next ="
	*lst = new;//update the head of lst (changing address) to address of new
}

/*creates new list node w/ content pointing to b, adds new node to head. Prints
  content of new node before & after ft_lstadd_front. Must cast return value to 
  (int *) and then dereference b/c structure variable type for content is void
int	main(void)
{
	t_list	*head;
	t_list	*new;
	int	a = 42;
	int	b = 7;

	head = ft_lstnew(&a);
	new = ft_lstnew(&b);
	printf("head content: %i\n", *(int *)(head->content));
	printf("new content: %i\n", *(int *)(new->content));
	ft_lstadd_front(&head, new);
	printf("head content: %i\n", *(int *)(head->content));
}*/
