/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:16:47 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/07/30 13:53:46 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* INCLUDE GUARD */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* LIBRARIES */
//stdlib contains malloc, free & exit
# include <stdlib.h>
//unistd library contains write & read
# include <unistd.h>
//stdio library contains printf, which I'll use for testing
# include <stdio.h>
//limits library contains INT_MIN & INT_MAX
# include <limits.h>

/* MY HEADER FILES */
//libft header file contains the prototypes of my libft functions
# include "libft/libft.h"
//ft_printf header file contains prototypes of my ft_printf functions
# include "ft_printf/ft_printf.h"

typedef	struct	s_list
{
	int		value;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

void	print_error(void);
long	ft_atol(const char *str);
void	validate_input(int argc, char **argv);

#endif
