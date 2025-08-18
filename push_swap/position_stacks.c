/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edwo-rei <edwo-rei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:55:21 by edwo-rei          #+#    #+#             */
/*   Updated: 2025/08/18 15:01:00 by edwo-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	efficient_rot(t_list **stack_a, t_list **stack_b, int rot_a, int rot_b)
{
	if (rot_a < rot_b)
	{
		while (rot_a)
		{
			rotate_both(stack_a, stack_b);
			rot_a--;
			rot_b--;
		}
		while (rot_b--)
			rotate_b(stack_b);
	}
	else if (rot_b < rot_a)
	{
		while (rot_b)
		{
			rotate_both(stack_a, stack_b);
			rot_a--;
			rot_b--;
		}
		while (rot_a--)
			rotate_a(stack_a);
	}
	else
		while (rot_a--)
			rotate_both(stack_a, stack_b);
}

void	efficient_rev_rot(t_list **stack_a, t_list **stack_b, int rot_a, int rot_b)
{
	if (rot_a > rot_b)
	{
		while (rot_a)
		{
			reverse_rotate_both(stack_a, stack_b);
			rot_a++;
			rot_b++;
		}
		while (rot_b++)
			reverse_rotate_b(stack_b);
	}
	else if (rot_b > rot_a)
	{
		while (rot_b)
		{
			reverse_rotate_both(stack_a, stack_b);
			rot_a++;
			rot_b++;
		}
		while (rot_a++)
			reverse_rotate_a(stack_a);
	}
	else
		while (rot_a++)
			reverse_rotate_both(stack_a, stack_b);
}

//ID & execute # of movements necessary to rotate stacks a & b into pos to be 
//able to push the right node from stack a to stack b
void	position_stacks(t_list **stack_a, t_list **stack_b, int min_pos)
{
	int	rot_a;
	int	rot_b;
	int	stack_size;
	int	min_pos_value;
	t_list	*tmp;
	
	//find # of rotations to bring current node to top of stack a
	stack_size = find_stack_size(*stack_a);
	if (min_pos <= stack_size / 2)
		rot_a = min_pos;
	else
		rot_a = (stack_size - min_pos) * -1;
	while (min_pos--)
		tmp = tmp->next;
	//find # of rotations of b needed for current node to go in right place
	rot_b = find_rot_b(*stack_b, tmp->value);
	//indicate what should be done in all possible scenarios
	// - if rot_a & rot_b are pos, they both rotate, so rotate both the
	//   smaller of the two
	if (rot_a > 0 && rot_b > 0)
		efficient_rot(stack_a, stack_b, rot_a, rot_b);
	//if rot_a & rot_b are both neg, they both reverse rotate
	else if (rot_a < 0 && rot_b < 0)
		efficient_rev_rot(stack_a, stack_b, rot_a, rot_b);
	else if (rot_a > 0 && rot_b < 0)
	{
		while (rot_a--)
				rotate_a(stack_a);
		while (rot_b++)
			reverse_rotate_b(stack_b);
	}
	else if (rot_a < 0 && rot_b > 0)
	{
		while (rot_a++)
				reverse_rotate_a(stack_a);
		while (rot_b--)
				rotate_b(stack_b);
	}
	//if rot_a * rot_b = 0, at least one of the two is 0, already in right
	//pos, so just need to return the other # of rotations - which may also
	//be 0
	else
	{
		if (rot_a > 0)
			while (rot_a--)
				rotate_a(stack_a);
		else if (rot_a < 0)
			while (rot_a++)
				reverse_rotate_a(stack_a);
		else if (rot_b > 0)
			while (rot_b--)
				rotate_b(stack_b);
		else if (rot_b < 0)
			while (rot_b++)
				reverse_rotate_b(stack_b);
	}
}
