/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:22:03 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/05/15 20:19:29 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
   typedef struct s_list
   {
	void			*content;
	struct s_list	*next;
   }					t_list;
   ^above was included in libft.h above functions to define struct s_list*/

t_list	*ft_lstnew(void *content)
{
	t_list *elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	(*elem).content = content;
	(*elem).next = NULL;
	return (elem);
}

/*creates new list node elem w/ content pointing to i, must cast return value 
  to (int *) and then dereference*/
int	main(void)
{
	int	i;
	t_list	*elem;

	i = 42;
	elem = ft_lstnew(&i);
	printf("%i\n", *(int *)(elem->content));
}
