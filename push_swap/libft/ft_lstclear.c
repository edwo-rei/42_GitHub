/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:17:35 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/17 14:15:49 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//(*del) is a function ptr to the function that follows this one
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

/*delete function referred to by (*del)
void	del(void *content)
{
	free(content);
}

/*creates new list node w/ content pointing to b, adds new node to tail. Prints
  content of all nodes. Then deletes newly added node and prints size of list.
  Must cast return value to (int *) and then dereference  b/c structure 
  variable type for content is void
int	main(void)
{
	t_list	*head;
	t_list	*new;
	//must alloc mem for a & b b/c can't free stack memory (used for
	//directly assigned variables
	int	*a = malloc(sizeof(int));
	int	*b = malloc(sizeof(int));

	*a = 42;
	*b = 7;
	head = ft_lstnew(a);
	new = ft_lstnew(b);
	printf("head content: %i\n", *(int *)(head->content));
	printf("new content: %i\n", *(int *)(new->content));
	ft_lstadd_back(&head, new);
	printf("head content: %i\n", *(int *)(head->content));
	ft_lstclear(&head, del);
	printf("list size: %i\n", ft_lstsize(head));
}*/
