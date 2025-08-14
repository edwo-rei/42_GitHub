/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:16:47 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/13 19:49:55 by edwo-rei         ###   ########.fr       */
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
int		check_if_sorted(t_list *stack_a);
t_list	*create_stack(int argc, char **argv);
t_list	*go_to_last(t_list *stack);
int		find_stack_size(t_list *stack);
void	free_stack(t_list **stack);
int		find_min_value(t_list *stack);
int		find_max_value(t_list *stack);
int		find_min_pos(t_list *stack);
int		find_max_pos(t_list *stack);
void	raise_min_a(t_list **stack_a, int argc, int min_pos);
void	push_to_b(t_list **stack_a, t_list **stack_b);
void	push_to_a(t_list **stack_a, t_list **stack_b);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_both(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b, int argc);
int		find_target_index(t_list *stack, int value);
int		find_rotations_b(t_list *stack, int value);

#endif
