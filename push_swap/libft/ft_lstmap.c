/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:16:14 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/17 15:04:07 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//(*f) is a function ptr to the function that follows this one
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*tmp;
	
	new_list = NULL;
	tmp = lst;
	while (tmp)
	{
		new_node = ft_lstnew(f(tmp->content));
		if (!new_node)
			{
				ft_lstclear(&new_list, del);
				return (NULL);
			}
		ft_lstadd_back(&new_list, new_node);
		tmp = tmp->next;
	}
	return (new_list);
}

/*function referred to by (*f)
void	*function(void *content)
{
	int	*new_int;

	new_int = malloc(sizeof(int));
	*new_int = *(int *)content + 1;
	return (new_int);
}

//delete function referred to by (*del)
void	del(void *content)
{
	free(content);
}

/*creates new list node w/ content pointing to b, adds new node to tail. Prints
  content of all nodes. Then increases content of nodes by 1 & creates a new
  list using ft_strmap, assigns it to a new prt. Finish by freeing old & new
  lists. Must cast return value to (int *) and then dereference  b/c structure 
  variable type for content is void
int	main(void)
{
	t_list	*head;
	t_list	*new;
	t_list	*list;
	t_list	*tmp;
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
	list = ft_lstmap(head, function, del);
	tmp = list;
	while (tmp)
	{
		printf("list content: %i\n", *(int *)(tmp->content));
		tmp = tmp->next;
	}
	ft_lstclear(&head, del);
	ft_lstclear(&list, del);
}*/
