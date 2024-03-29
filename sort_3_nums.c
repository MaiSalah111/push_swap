/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:09:32 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/23 17:07:22 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_nums(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = stack_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	push_prep(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	move_min_to_top(t_stack **a)
{
	while ((*a)->nbr != stack_min(*a)->nbr)
	{
		if (stack_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
