/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 12:28:02 by maiahmed          #+#    #+#             */
/*   Updated: 2024/03/31 12:28:13 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index_median(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
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

void	push_b_to_a(t_stack **a, t_stack **b)
{
	push_prep(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	free_split_array(char **split_array)
{
	int	i;

	i = 0;
	while (split_array[i] != NULL)
	{
		free(split_array[i]);
		i++;
	}
	free(split_array);
}
