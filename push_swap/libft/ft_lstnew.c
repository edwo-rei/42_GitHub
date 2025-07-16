/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:22:03 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/16 18:05:34 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;//same as "(*node).content = content;"
	node->next = NULL;//same as "(*node).next = NULL;"
	return (node);
}

/*creates new list node  w/ content pointing to i, must cast return value 
  to (int *) and then dereference b/c structure variable type for content
  is void
int	main(void)
{
	int	i;
	t_list	*node;

	i = 42;
	node = ft_lstnew(&i);
	printf("%i\n", *(int *)(node->content));
}*/
